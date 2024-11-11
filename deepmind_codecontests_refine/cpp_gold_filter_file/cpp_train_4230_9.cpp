#include <bits/stdc++.h>
int const maxn = 100007;
int const inf = 1 << 30;
struct node {
  node *child[2], *parent;
  int lmax, rmin, index, num;
} memory[maxn], *root = memory;
std::vector<int> inter;
int number[maxn], parent[maxn];
double expect[maxn];
bool has_child[maxn];
int n, k;
std::pair<int, int> get_min_max(node* now) {
  if (!now) return {0, inf};
  std::pair<int, int> tmp;
  auto t1 = get_min_max(now->child[0]);
  auto t2 = get_min_max(now->child[1]);
  now->lmax = t1.first;
  now->rmin = t2.second;
  tmp.first = std::max(now->num, std::max(t1.first, t2.first));
  tmp.second = std::min(now->num, std::min(t1.second, t2.second));
  return tmp;
}
void dfs(node* now, int deep, long long sum) {
  if (!now) return;
  if (!has_child[now->index]) {
    int id =
        std::upper_bound(inter.begin(), inter.end(), now->num) - inter.begin();
    expect[id] = sum / double(deep);
    return;
  }
  dfs(now->child[0], deep + 1, sum + now->rmin);
  dfs(now->child[1], deep + 1, sum + now->lmax);
}
void print(node* now) {
  if (!now) return;
  print(now->child[0]);
  std::cerr << ":: " << now->num;
  print(now->child[1]);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> parent[i] >> number[i];
  for (int i = 1, p, num; i <= n; i++) {
    p = parent[i];
    num = number[i];
    if (p == -1)
      root = memory + i;
    else
      memory[i].parent = memory + p;
    memory[p].child[(num > number[p])] = memory + i;
    memory[i].num = num;
    memory[i].index = i;
    has_child[p] = true;
  }
  for (int i = 1; i <= n; i++)
    if (has_child[i]) inter.push_back(memory[i].num);
  inter.push_back(-inf);
  inter.push_back(inf);
  std::sort(inter.begin(), inter.end());
  get_min_max(root);
  dfs(root, 0, 0);
  std::cin >> k;
  for (int i = 0, x; i < k; i++) {
    std::cin >> x;
    int id = std::upper_bound(inter.begin(), inter.end(), x) - inter.begin();
    double d = expect[id];
    std::printf("%.11lf\n", d);
  }
}

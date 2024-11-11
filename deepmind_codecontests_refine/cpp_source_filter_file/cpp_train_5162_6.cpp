#include <bits/stdc++.h>
using namespace std;
int n, k;
struct subtree {
  unsigned long long waystoroot[5], sumtoroot[5];
  unsigned long long inside;
  subtree() {
    inside = 0;
    for (int i = 0; i < k; i++) {
      waystoroot[i] = sumtoroot[i] = 0;
    }
  }
};
vector<int> tree[200001];
void merge(subtree &first, subtree &second) {
  first.inside += second.inside;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      first.inside += first.waystoroot[i] * second.sumtoroot[j] +
                      first.sumtoroot[i] * second.waystoroot[j];
      if (i + j >= k)
        first.inside -= (first.waystoroot[i] * second.waystoroot[j]);
    }
    first.sumtoroot[i] += second.sumtoroot[i];
    first.waystoroot[i] += second.waystoroot[i];
  }
}
subtree dfs(int cur, int par) {
  vector<subtree> subvc;
  for (auto &x : tree[cur]) {
    if (x == par) continue;
    subvc.push_back(dfs(x, cur));
  }
  if (subvc.empty()) return subtree();
  for (auto &x : subvc) {
    int tmpways[5], tmpsum[5];
    for (int i = 1; i < k; i++) {
      x.inside += x.sumtoroot[i];
      tmpways[i - 1] = x.waystoroot[i];
      tmpsum[i - 1] = x.sumtoroot[i];
    }
    x.inside += x.sumtoroot[0];
    tmpways[k - 1] = x.waystoroot[0];
    tmpsum[k - 1] = x.sumtoroot[0] + x.waystoroot[0];
    tmpsum[k - 1]++, tmpways[k - 1]++;
    for (int i = 0; i < k; i++)
      x.sumtoroot[i] = tmpsum[i], x.waystoroot[i] = tmpways[i];
  }
  for (int i = 1; i < subvc.size(); i++) merge(subvc[0], subvc[i]);
  return subvc[0];
}
int main() {
  int a, b;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  subtree subrez = dfs(1, 1);
  unsigned long long rez = subrez.inside;
  for (int i = 0; i < k; i++) rez += subrez.sumtoroot[i];
  cout << rez << endl;
  return 0;
}

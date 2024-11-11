#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
const int N = 1e5 + 10;
int p[N];
vector<int> v, primo;
set<int> onde[N];
vector<pair<int, int> > resp;
int n;
int troca(int pos1, int pos2) {
  if (pos1 == pos2) return 0;
  if (pos1 > pos2) swap(pos1, pos2);
  int dist = pos2 - pos1 + 1;
  int x = upper_bound(primo.begin(), primo.end(), dist) - primo.begin() - 1;
  x = primo[x];
  x = pos2 - x + 1;
  onde[v[pos2]].erase(pos2);
  onde[v[x]].erase(x);
  onde[v[pos2]].insert(x);
  onde[v[x]].insert(pos2);
  resp.push_back(make_pair(x, pos2));
  swap(v[pos2], v[x]);
  return troca(pos1, x) + 1;
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i < N; i++) {
    if (!p[i]) {
      for (int j = 2 * i; j < N; j += i) p[j] = 1;
      primo.push_back(i);
    }
  }
  v.push_back(0);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }
  for (int i = 1; i <= n; i++) onde[v[i]].insert(i);
  vector<int> aux = v;
  sort(aux.begin(), aux.end());
  for (int i = 1; i <= n; i++) {
    int x = troca(i, *onde[aux[i]].begin());
    assert(x <= 5);
    onde[aux[i]].erase(i);
  }
  printf("%d\n", (int)resp.size());
  for (pair<int, int> x : resp) {
    printf("%d ", x.first);
    printf("%d\n", x.second);
  }
  return 0;
}

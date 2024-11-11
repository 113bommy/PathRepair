#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
map<unsigned long long, int> mp;
vector<int> g[2 * N];
unsigned long long a[2 * N];
unsigned long long rr[2 * N];
unsigned long long n, k;
int get_ans(int id) {
  int num = a[id];
  int pp = lower_bound(rr + 1, rr + 1 + n, num) - rr;
  pp--;
  for (int i = 0; i < g[id].size(); i++) {
    int v = g[id][i];
    if (a[v] <= a[id]) {
      pp--;
    }
  }
  return max(0, pp);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i < (n + 1); ++i) {
    scanf("%lld", &rr[i]);
    a[i] = rr[i];
  }
  sort(rr + 1, rr + n + 1);
  for (int i = 0; i < (k); ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i < (n + 1); ++i) {
    cout << get_ans(i) << " ";
  }
  return 0;
}

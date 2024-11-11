#include <bits/stdc++.h>
using namespace std;
const double pai = acos(-1);
const double eps = 1e-10;
const long long mod = 1e9 + 7;
const int MX = 1e6 + 5;
vector<int> g[MX];
int in[MX], ou[MX];
void JT(int m) {
  while (m--) {
    int sa, sb;
    scanf("%d %d", &sa, &sb);
    if (sa > sb) swap(sa, sb);
    g[sa].push_back(sb);
    in[sa]++, ou[sb]++;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  JT(m);
  int qc;
  cin >> qc;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = ans + in[i] * ou[i];
  }
  cout << ans << '\n';
  while (qc--) {
    int cg;
    cin >> cg;
    ans -= in[cg] * ou[cg];
    for (auto i : g[cg]) {
      ans -= in[i] * ou[i];
      g[i].push_back(cg);
      in[i]++, ou[i]--;
      ans += in[i] * ou[i];
    }
    g[cg].clear();
    ou[cg] = in[cg] + ou[cg], in[cg] = 0;
    cout << ans << '\n';
  }
  return 0;
}

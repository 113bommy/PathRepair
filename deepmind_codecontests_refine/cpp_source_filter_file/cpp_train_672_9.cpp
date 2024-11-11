#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 2e5 + 5;
const int M = 5e5 + 5;
int n, m, a[N], freq[M];
long long ans;
bool f[N];
vector<int> p[M];
void solve(int x, bool add) {
  int sz = p[x].size();
  for (int i = 1; i < (1 << sz); i++) {
    int cnt = 0, num = 1;
    for (int j = 0; j < sz; j++)
      if ((1 << j) & i) cnt++, num *= p[x][j];
    if (add) {
      if (cnt & 1)
        ans += freq[num];
      else
        ans -= freq[num];
      freq[num]++;
    } else {
      freq[num]--;
      if (cnt & 1)
        ans -= freq[num];
      else
        ans += freq[num];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 2; i < N; i++)
    if (!p[i].size())
      for (int j = i; j < N; j += i) p[j].push_back(i);
  int cnt = 0;
  while (m--) {
    int x;
    cin >> x;
    if (f[x])
      cnt--, solve(a[x], 0);
    else
      cnt++, solve(a[x], 1);
    f[x] ^= 1;
    cout << 1ll * cnt * (cnt - 1) / 2 - ans << '\n';
  }
  return 0;
}

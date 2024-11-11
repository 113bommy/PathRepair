#include <bits/stdc++.h>
using namespace std;
int m;
string st, s[211111];
int fu[211111], inv[211111];
int su[211111], ans[211111];
vector<int> need[211111];
int ty[211111], nn[211111];
int p25[211111];
int pv(int a, int b) {
  if (b == 0) return 1;
  long long r = pv(a, b / 2);
  r = r * r % 1000000007;
  if (b % 2) r = r * a % 1000000007;
  return r;
}
int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fu[n] * 1ll * inv[k] % 1000000007 * inv[n - k] % 1000000007;
}
int main() {
  ios::sync_with_stdio(false);
  p25[0] = 1;
  for (int i = 1; i < 211111; i++) p25[i] = p25[i - 1] * 25ll % 1000000007;
  cin >> m;
  cin >> st;
  int curl = st.size();
  for (int i = 0; i < m; i++) {
    cin >> ty[i];
    if (ty[i] == 1) {
      cin >> s[i];
      curl = s[i].size();
    } else {
      need[curl].push_back(i);
      cin >> nn[i];
    }
  }
  fu[0] = 1;
  for (int i = 1; i < 211111; i++) fu[i] = fu[i - 1] * 1ll * i % 1000000007;
  for (int i = 0; i < 211111; i++)
    inv[i] = pv(fu[i], 1000000007 - 2) % 1000000007;
  for (int d = 1; d < 211111; d++)
    if (need[d].size() > 0) {
      for (int i = 1; i <= 100000; i++) {
        if (i < d) {
          su[i] = 0;
          continue;
        }
        su[i] = C(i - 1, d - 1) * 1ll * p25[d - i] % 1000000007;
      }
      for (int i = 1; i <= 100000; i++)
        su[i] = (su[i - 1] * 26ll + su[i]) % 1000000007;
      for (int i = 0; i < need[d].size(); i++)
        ans[need[d][i]] = su[nn[need[d][i]]];
    }
  for (int i = 0; i < m; i++)
    if (ty[i] == 2) cout << ans[i] << endl;
  return 0;
}

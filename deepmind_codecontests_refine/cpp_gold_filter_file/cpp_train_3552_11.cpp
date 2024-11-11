#include <bits/stdc++.h>
using namespace std;
int n, m;
long long h[257][257];
long long vf[257][26];
bool ok[257][257][257];
long long pwr(long long a, long long b) {
  if (b == 0) return 1;
  long long p = pwr(a, b / 2);
  if (b & 1) return p * a % 1000000007 * p % 1000000007;
  return p * p % 1000000007;
}
long long v[257];
long long lg1[257], lg2[257];
long long manacher() {
  long long ans = 0;
  memset(lg1, 0, sizeof(lg1));
  memset(lg2, 0, sizeof(lg2));
  long long pog = -1, p = -1, pt = 0;
  for (int i = 1; i <= n; i++)
    if (v[i] != -1) {
      lg1[i] = 1;
      lg2[i] = 0;
      if (i <= pog) lg1[i] = min(lg1[p - (i - p) + pt], pog - i + 1);
      if (i < pog) lg2[i] = min(lg2[p - (i - p) - !pt], pog - i);
      while (i - lg1[i] >= 1 && i + lg1[i] <= n &&
             v[i - lg1[i]] == v[i + lg1[i]] && v[i - lg1[i]] != -1)
        lg1[i]++;
      while (i - lg2[i] >= 1 && i + lg2[i] + 1 <= n &&
             v[i - lg2[i]] == v[i + lg2[i] + 1] && v[i - lg2[i]] != -1)
        lg2[i]++;
      if (i + lg1[i] - 1 > pog) {
        pog = i + lg1[i] - 1;
        p = i;
        pt = 0;
      }
      if (i + lg2[i] > pog) {
        pog = i + lg2[i];
        p = i;
        pt = 1;
      }
      ans += lg1[i] + lg2[i];
    }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) memset(vf[j], 0, sizeof(vf[j]));
    string s;
    cin >> s;
    for (int j = 1; j <= m; j++)
      h[i][j] = (h[i][j - 1] + pwr(257, s[j - 1] - 'a')) % 1000000007;
    for (int j2 = 1; j2 <= m; j2++) {
      memcpy(vf[j2], vf[j2 - 1], sizeof(vf[j2]));
      vf[j2][s[j2 - 1] - 'a']++;
      for (int j1 = 1; j1 <= j2; j1++) {
        int imp = 0;
        for (int c = 0; c < 26; c++)
          if ((vf[j2][c] - vf[j1 - 1][c]) & 1) imp++;
        if (imp <= 1) ok[i][j1][j2] = 1;
      }
    }
  }
  long long ans = 0;
  for (int j1 = 1; j1 <= m; j1++)
    for (int j2 = j1; j2 <= m; j2++) {
      for (int i = 1; i <= n; i++) {
        v[i] = (h[i][j2] - h[i][j1 - 1] + 1000000007) % 1000000007;
        if (!ok[i][j1][j2]) v[i] = -1;
      }
      ans += manacher();
    }
  cout << ans << "\n";
  return 0;
}

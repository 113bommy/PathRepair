#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10, maxK = 510, maxL = 26;
int ans, lf[maxK], rg[maxK], cnt[maxN], ps[maxN][maxL];
int k, L, R, lb[maxK], rb[maxK];
char tp[maxK];
inline void modify(int p, int z) {
  if (cnt[p] < L || cnt[p] >= R) return;
  ans += z;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < maxL; j++) ps[i + 1][j] = ps[i][j];
    ps[i + 1][s[i] - 'a']++;
  }
  cin >> k >> L >> R;
  R++;
  for (int i = 0; i < k; i++) {
    cin >> tp[i] >> lb[i] >> rb[i];
    lf[i] = rg[i] = n;
  }
  long long res = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (L == 0) ans++;
    for (int j = 0; j < k; j++) {
      int curr = (int)tp[j] - 'a';
      while (lf[j] >= 0 && ps[lf[j]][curr] - ps[i][curr] >= lb[j])
        lf[j]--, modify(lf[j], -1), cnt[lf[j]]++, modify(lf[j], +1);
      while (rg[j] >= 0 && ps[rg[j]][curr] - ps[i][curr] > rb[j])
        rg[j]--, modify(rg[j], -1), cnt[rg[j]]--, modify(rg[j], +1);
    }
    res += ans;
  }
  cout << res << endl;
}

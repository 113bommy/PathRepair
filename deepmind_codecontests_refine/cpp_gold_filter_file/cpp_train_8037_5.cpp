#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n, t, a, b, ai;
  cin >> m;
  while (m--) {
    cin >> n >> t >> a >> b;
    bool tp[200005];
    for (int i = 0; i < n; i++) cin >> tp[i];
    vector<pair<long long, long long> > v;
    long long totE = 0, totH = 0;
    for (int i = 0; i < n; i++) {
      cin >> ai;
      v.push_back({ai, tp[i]});
      totE += !tp[i];
      totH += tp[i];
    }
    v.push_back({t + 1, 0});
    sort(v.begin(), v.end());
    long long cntE = 0, cntH = 0, ans = 0;
    for (int i = 0; i <= n;) {
      long long need = (cntE * a) + (cntH * b);
      long long ext = v[i].first - 1ll - need;
      if (0 <= ext) {
        long long canA = min((totE - cntE), ext / a);
        ext -= (canA * a);
        long long canB = min((totH - cntH), ext / b);
        ans = max(ans, cntH + cntE + canA + canB);
      }
      int j;
      for (j = i; j <= n && v[i].first == v[j].first; j++)
        if (v[j].second)
          cntH++;
        else
          cntE++;
      i = j;
    }
    cout << ans << "\n";
  }
}

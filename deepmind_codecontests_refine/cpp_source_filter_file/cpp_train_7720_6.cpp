#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 9, MOD = 1e9 + 7;
using vi = vector<long long>;
using vb = vector<bool>;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long q;
  cin >> q;
  for (long long j = 0; j < q; j++) {
    long long n;
    cin >> n;
    vi a;
    for (long long i = 0; i < n; i++) {
      long long k;
      cin >> k;
      a.push_back(k);
    }
    sort(a.rbegin(), a.rend());
    a.erase(unique(a.begin(), a.end()), a.end());
    long long ans = a[0];
    for (long long i = 0; i < a.size() - 1; i++) {
      for (long long i1 = i + 1; i1 < a.size(); i1++) {
        if (a[i] % a[i1]) {
          ans = max(ans, a[i] + a[i1]);
          break;
        }
      }
    }
    for (long long i = 0; i < a.size() - 2 && a[i] + a[i + 1] + a[i + 2] > ans;
         i++) {
      for (long long i1 = i + 1;
           i1 < a.size() - 1 && a[i] + a[i1] + a[i - 1] > ans; i1++) {
        if (a[i] % a[i1] == 0) continue;
        for (long long i3 = i1 + 1; i3 < a.size() && a[i] + a[i1] + a[i3] > ans;
             i3++) {
          if (a[i] % a[i1] && a[i] % a[i3]) {
            ans = max(ans, a[i] + a[i1] + a[i3]);
            break;
          }
        }
      }
    }
    cout << ans << "\n";
  }
}

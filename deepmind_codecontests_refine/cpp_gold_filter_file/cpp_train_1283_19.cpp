#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 42;
int s[MAXN], as[MAXN], sc, cand[MAXN], cc, a[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] > 0 ? s[a[i]]++, sc++ : as[-a[i]]++;
  }
  for (int i = 1; i <= n; ++i) {
    if (n - (as[i] + sc - s[i]) == m) cand[i] = 1, cc++;
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] > 0) {
      if (cand[a[i]] == 1)
        cout << (cc == 1 ? "Truth\n" : "Not defined\n");
      else
        cout << "Lie\n";
    } else {
      if (cand[-a[i]] == 1)
        cout << (cc == 1 ? "Lie\n" : "Not defined\n");
      else
        cout << "Truth\n";
    }
  }
}

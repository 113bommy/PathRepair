#include <bits/stdc++.h>
const int Inf = 2 * 1000 * 1000 * 1000;
long long LINF = (long long)4e18;
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  vector<int> pref(m, 1e9);
  vector<int> suf(m, 1e9);
  int p1 = 0;
  int p2 = 0;
  while (p1 < n) {
    if (a[p1] == b[p2]) {
      pref[p2] = p1 + 1;
      p2++;
    }
    p1++;
  }
  if (pref[m - 1] <= m) {
    cout << b;
    return 0;
  }
  p1 = 0;
  p2 = 0;
  reverse((a).begin(), (a).end());
  reverse((b).begin(), (b).end());
  while (p1 < n) {
    if (a[p1] == b[p2]) {
      suf[m - p2 - 1] = p1 + 1;
      p2++;
    }
    p1++;
  }
  reverse((a).begin(), (a).end());
  reverse((b).begin(), (b).end());
  int low = 1, high = m - 1;
  while (low < high) {
    int mid = (low + high) / 2;
    int ok = 0;
    for (int i = mid - 1; i < m; i++) {
      if (i - mid < 0) {
        ok |= suf[i + 1] <= n;
      } else if (i == m - 1) {
        ok |= pref[i - mid] <= n;
      } else {
        ok |= (suf[i + 1] + pref[i - mid]) <= n;
      }
    }
    if (ok)
      high = mid;
    else
      low = mid + 1;
  }
  for (int i = low - 1; i < m; i++) {
    if (i - low < 0) {
      if (suf[i + 1] <= n) {
        for (int j = i + 1; j < m; j++) {
          cout << b[j];
        }
        return 0;
      }
    } else if (i == m - 1) {
      if (pref[i - low] <= n) {
        for (int j = 0; j < i - low + 1; j++) {
          cout << b[j];
        }
        return 0;
      }
    } else {
      if ((suf[i + 1] + pref[i - low]) <= n) {
        int lg = i - low + 1;
        int rg = i;
        for (int j = 0; j < m; j++) {
          if (lg <= j && j <= rg) continue;
          cout << b[j];
        }
        return 0;
      }
    }
  }
  cout << '-';
  return 0;
}

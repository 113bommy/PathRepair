#include <bits/stdc++.h>
using namespace std;
void __dbg() { cout << endl; }
template <typename Arg, typename... Args>
void __dbg(Arg A, Args... B) {
  cout << ' ' << A;
  __dbg(B...);
}
const int inf = INT_MAX;
const int ninf = INT_MIN;
const int mod = 1e9 + 7;
const int maxN = 1e6 + 2;
int main() {
  string a, b;
  cin >> a >> b;
  int n = (int)a.size(), m = (int)b.size();
  vector<int> pref(m + 1, -1), suff(m + 1, -1);
  int i = 0, j = 0;
  while (i < m && j < n) {
    if (b[i] == a[j]) {
      pref[i] = j;
      i++;
      j++;
    } else {
      j++;
    }
  }
  i = m - 1, j = n - 1;
  while (i >= 0 && j >= 0) {
    if (b[i] == a[j]) {
      suff[i] = j;
      i--;
      j--;
    } else {
      j--;
    }
  }
  int len = 0, L = -2, R = m;
  for (int i = 0; i < m; i++) {
    if (pref[i] == -1) break;
    int lo = i + 1, hi = m - 1, idx = -1;
    while (lo <= hi) {
      int mid = (lo + hi) / 2;
      if (suff[mid] > pref[i]) {
        idx = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    if (idx != -1) {
      int here = (i + 1) + (m - idx);
      if (here > len) {
        len = here;
        L = i, R = idx;
      }
    } else {
      int here = i + 1;
      if (here > len) {
        len = here;
        L = i, R = m;
      }
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    if (suff[i] == -1) break;
    int here = (m - i);
    if (here > len) {
      len = here;
      L = -1, R = i;
    }
  }
  if (L == -2) {
    cout << "-";
    exit(0);
  }
  for (int i = 0; i < L + 1; i++) cout << b[i];
  for (int i = R; i < m; i++) cout << b[i];
  return 0;
}

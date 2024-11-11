#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
const long long INF = 1e18;
const long double EPS = 1e-12;
int z[100005];
int z_[100005];
int zr_[100005];
int zr[100005];
int pref[100005];
int suff[100005];
int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  int q;
  cin >> q;
  int ans = 0;
  int cnt = 0;
  while (q--) {
    cnt++;
    for (int i = 0; i < (int)n; i++) {
      z[i] = 0;
      zr[i] = 0;
    }
    int l = -1;
    int r = -1;
    string t;
    cin >> t;
    int m = (int)t.size();
    for (int i = 0; i < (int)m; i++) {
      z_[i] = 0;
      zr_[i] = 0;
    }
    if (m == 1) continue;
    if (m > n) continue;
    for (int i = (int)1; i < (int)m; i++) {
      if (i > r) {
        l = r = i;
        while (r < m && t[r - l] == t[r]) {
          r++;
        }
        z_[i] = r - l;
        r--;
      } else {
        int k = i - l;
        if (z_[k] < r - i + 1) {
          z_[i] = z_[k];
        } else {
          l = i;
          while (r < m && t[r - l] == t[r]) {
            r++;
          }
          z_[i] = r - l;
          r--;
        }
      }
    }
    l = r = -1;
    for (int i = 0; i < (int)n; i++) {
      if (i > r) {
        l = r = i;
        while (r < n && r - l < m && t[r - l] == s[r]) {
          r++;
        }
        z[i] = r - l;
        r--;
      } else {
        int k = i - l;
        if (z_[k] < r - i + 1) {
          z[i] = z_[k];
        } else {
          l = i;
          while (r < n && r - l < m && t[r - l] == s[r]) {
            r++;
          }
          z[i] = r - l;
          r--;
        }
      }
    }
    l = r = m + 5;
    for (int i = m - 2; i >= 0; i--) {
      if (i < l) {
        l = r = i;
        while (l >= 0 && t[m - 1 - (r - l)] == t[l]) {
          l--;
        }
        zr_[i] = r - l;
        l++;
      } else {
        int k = r - i;
        if (zr_[m - 1 - (r - i)] > i - l + 1) {
          zr_[i] = zr_[m - 1 - (r - i)];
        } else {
          r = i;
          while (l >= 0 && t[m - 1 - (r - l)] == t[l]) {
            l--;
          }
          zr_[i] = r - l;
          l++;
        }
      }
    }
    l = r = n + 5;
    for (int i = n - 1; i >= 0; i--) {
      if (i < l) {
        l = r = i;
        while (l >= 0 && m - 1 >= (r - l) && t[m - 1 - (r - l)] == s[l]) {
          l--;
        }
        zr[i] = r - l;
        l++;
      } else {
        int k = r - i;
        if (zr_[m - 1 - (k)] < i - l + 1) {
          zr_[i] = zr_[m - 1 - k];
        } else {
          r = i;
          while (l >= 0 && m - 1 >= (r - l) && t[m - 1 - (r - l)] == s[l]) {
            l--;
          }
          zr[i] = r - l;
          l++;
        }
      }
    }
    for (int i = 0; i < (int)m + 1; i++) {
      pref[i] = n + 5;
      suff[i] = -1;
    }
    int mx = -1;
    for (int i = 0; i < (int)n; i++) {
      if (z[i] > mx) {
        for (int j = (int)mx + 1; j < (int)z[i] + 1; j++) {
          pref[j] = i;
        }
        mx = z[i];
      }
    }
    mx = -1;
    for (int i = n - 1; i >= 0; i--) {
      if (zr[i] > mx) {
        for (int j = (int)mx + 1; j < (int)zr[i] + 1; j++) {
          suff[j] = i;
        }
        mx = zr[i];
      }
    }
    for (int i = 0; i < (int)m + 1; i++) {
      if (suff[m - i] - pref[i] >= m - 1) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

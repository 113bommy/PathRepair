#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 3;
int n, p[N], pac, pref[N], tmp[N];
int cnt(int l, int r) {
  if (r < l) return 0;
  return pref[r] - pref[l - 1];
}
bool sat(int d) {
  bool flag = 1;
  for (int i = 1; i < pac; i++) {
    if (cnt(tmp[i - 1] + 1, p[i] - d - 1)) {
      flag = 0;
      break;
    } else if (cnt(tmp[i - 1] + 1, p[i] - 1) == 0)
      tmp[i] = p[i] + d;
    else if (i > 1 && cnt(tmp[i - 2] + 1, p[i] - d - 1) == 0)
      tmp[i] = max(p[i - 1] + d, p[i]);
    else
      tmp[i] = p[i];
  }
  return (flag && cnt(tmp[pac - 1] + 1, n) == 0);
}
int main() {
  cin >> n;
  pac = 1;
  int lt = -1, rt;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '*')
      pref[i + 1] = pref[i] + 1;
    else
      pref[i + 1] = pref[i];
    if (s[i] == 'P') p[pac++] = i + 1;
    if (lt == -1 && s[i] == '*') lt = i + 1;
    if (s[i] == '*') rt = i + 1;
  }
  if (pac == 2) {
    int x = pref[p[1]], y = pref[n] - pref[p[1] - 1];
    if (x > y)
      cout << x << " " << p[1] - lt << endl;
    else if (x < y)
      cout << y << " " << rt - p[1] << endl;
    else
      cout << x << " " << min(p[1] - lt, rt - p[1]) << endl;
    return 0;
  } else {
    int l = 1, r = n;
    while (l < r) {
      int m = (l + r) >> 1;
      if (sat(m))
        r = m;
      else
        l = m + 1;
    }
    cout << pref[n] << " " << l << endl;
  }
}

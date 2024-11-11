#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int oo = 0x3f3f3f3f;
int l[N], r[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a >> b;
  int n = (int)a.length(), m = (int)b.length();
  a = '.' + a;
  b = '.' + b;
  int curl = 1, curr = n;
  int mxl, mxr;
  int ii;
  for (ii = 1; ii <= m; ii++) {
    while (a[curl] != b[ii] && curl <= n) {
      curl++;
    }
    if (curl > n) {
      break;
    }
    l[ii] = curl;
    curl++;
  }
  mxl = ii - 1;
  for (ii = 1; ii <= m; ii++) {
    while (a[curr] != b[m - ii + 1] && curr >= 1) {
      curr--;
    }
    if (curr < 1) {
      break;
    }
    r[ii] = curr;
    curr--;
  }
  mxr = ii - 1;
  int ansl = 0, ansr = mxr, mx = mxr;
  for (int i = 1; i <= mxl; i++) {
    while ((l[i] >= r[mxr] && mxr > 0) || mxr + i > n) mxr--;
    if (i + mxr > mx) {
      mx = i + mxr;
      ansl = i;
      ansr = mxr;
    }
  }
  string res = "";
  for (int i = 1; i <= ansl; i++) res += b[i];
  for (int i = m - ansr + 1; i <= m; i++) res += b[i];
  if (res == "")
    cout << "-";
  else
    cout << res;
}

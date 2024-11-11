#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T bigmod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
char pp[55][55];
int nxt[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> pp[i];
  int cnt = 0;
  int mxx = -1, mxy = -1, mnx = 55, mny = 55;
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) {
      if (pp[i][j] == '4') {
        mxx = max(mxx, i);
        mxy = max(mxy, j);
        mnx = min(mnx, i);
        mny = min(mny, j);
        cnt++;
      }
    }
  }
  if (mxx == -1 || cnt != (mxx - mnx + 1) * (mxy - mny + 1)) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = mnx - 1; i <= mxx + 1; i++) {
    for (int j = mny - 1; j <= mxy + 1; j++) {
      if (i < 0 || i >= n || j < 0 || j >= n || pp[i][j] == '4') continue;
      int cc = 0;
      for (int k = (0); k < (4); ++k) {
        int x = i + nxt[k][0];
        int y = j + nxt[k][1];
        if (mnx - 1 <= x && x <= mxx + 1 && mny - 1 <= y && y <= mxy + 1) cc++;
      }
      if (pp[i][j] - '0' != cc) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (n); ++j) {
      if (mnx - 1 <= i && i <= mxx + 1 && mny - 1 <= j && j <= mny + 1)
        continue;
      if (pp[i][j] != '0') {
        cout << "No" << endl;
        return 0;
      }
    }
  cout << "Yes" << endl;
}

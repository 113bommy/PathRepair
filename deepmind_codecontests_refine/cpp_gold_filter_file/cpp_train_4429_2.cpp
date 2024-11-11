#include <bits/stdc++.h>
using namespace std;
short p[55], t[55];
int main() {
  short n, c;
  int l = 0, r = 0, tt;
  cin >> n >> c;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  tt = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    tt += t[i];
    l += max(0, p[i] - c * tt);
  }
  tt = 0;
  for (int i = n; i >= 1; --i) {
    tt += t[i];
    r += max(0, p[i] - c * tt);
  }
  if (r > l) {
    cout << "Radewoosh";
  } else if (l > r) {
    cout << "Limak";
  } else {
    cout << "Tie";
  }
  return 0;
}

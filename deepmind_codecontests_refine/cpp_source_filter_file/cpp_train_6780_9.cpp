#include <bits/stdc++.h>
using namespace std;
string w;
int k, q, s, n;
int l, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> w >> k;
  n = w.size();
  for (int i = 0; i < n; i++) {
    if (w[i] == '?') q++;
    if (w[i] == '*') s++;
  }
  l = n - 2 * (q + s);
  if (s > 0)
    r = 200;
  else
    r = n - (q + s);
  if (!(k >= l and k <= r)) {
    cout << "Impossible \n";
    return 0;
  }
  int extra = k - (n - q - s);
  if (extra >= 0) {
    bool check = false;
    for (int i = 0; i < n; i++) {
      if (w[i] != '*' and w[i] != '?') cout << w[i];
      if (i == n - 1) continue;
      if (w[i + 1] == '*' and check == false) {
        for (int j = 0; j < extra; j++) cout << w[i];
        check = false;
      }
    }
    cout << "\n";
    return 0;
  } else {
    int am = -1 * extra;
    for (int i = 0; i < n; i++) {
      if (w[i] != '*' and w[i] != '?') {
        if (i == n - 1) {
          cout << w[i];
          continue;
        }
        if ((w[i + 1] == '?' or w[i + 1] == '*') and am > 0) {
          am--;
          continue;
        } else
          cout << w[i];
      }
    }
    cout << "\n";
    return 0;
  }
}

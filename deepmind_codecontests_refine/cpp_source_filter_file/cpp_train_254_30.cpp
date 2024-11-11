#include <bits/stdc++.h>
using namespace std;
const float eps = 1e-8;
const long long lloo = 1e18;
const int oo = (1e9) + 10;
int dau[200010], a[200010];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n + k; i++) a[i] = oo;
  for (int i = 0; i < n; i++) {
    a[i] = 0;
    string s;
    cin >> s;
    if (s == "?")
      dau[i] = 1;
    else {
      int l = 0;
      if (s[0] == '-') l = 1;
      for (int j = l, _b = s.size() - 1; j <= _b; j++) {
        a[i] = a[i] * 10 + s[j] - '0';
      }
      if (l == 1) a[i] = -a[i];
    }
  }
  for (int i = 0, _b = k - 1; i <= _b; i++) {
    int y = i - k;
    int val = -oo;
    for (int x = i; x < n + k; x += k) {
      if (dau[x] == 0) {
        int len = (x - y) / k - 2;
        int l = -len / 2, r = len + l;
        if (a[x] <= len) {
          l -= r - (a[x] - 1);
          r -= r - (a[x] - 1);
        }
        int vec = 0;
        if (val >= l) {
          vec = val + 1 - l;
          l += vec;
          r += vec;
        }
        if (r >= a[x]) {
          cout << "Incorrect sequence";
          return 0;
        }
        for (y += k; y < x; y += k) {
          a[y] = l++;
        }
        val = a[x];
      }
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
}

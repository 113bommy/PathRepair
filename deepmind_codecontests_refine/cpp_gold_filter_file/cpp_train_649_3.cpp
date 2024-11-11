#include <bits/stdc++.h>
using namespace std;
const int maxN = 20, inf = 1000 * 1000 * 1000;
int i, n, ans, t, j, k, a[maxN], b[maxN], c[maxN], d[maxN], nul, h;
bool f;
string s;
int main() {
  getline(cin, s);
  n = s.length();
  for (i = 0; i < n; ++i) {
    ++a[s[i] - '0'];
  }
  j = 0;
  ans = 0;
  k = 0;
  for (i = 1; i <= 9; ++i) {
    for (j = 0; j < 10; ++j) {
      b[j] = a[j];
      c[j] = a[j];
    }
    t = 0;
    if (b[i] > 0 && c[10 - i] > 0) {
      --b[i];
      --c[10 - i];
      ++t;
      for (j = 0; j < 10; ++j) {
        t += min(b[j], c[9 - j]);
      }
      if (t > ans) {
        ans = t;
        k = i;
      }
    }
  }
  for (i = 0; i < 10; ++i) {
    b[i] = a[i];
    c[i] = a[i];
  }
  f = false;
  if (b[k] > 0 && c[10 - k] > 0) {
    --b[k];
    --c[10 - k];
    f = true;
  }
  h = min(c[0] - min(b[9], c[0]), b[0] - min(b[0], c[9]));
  for (i = 0; i < b[0] - h - min(b[0], c[9]); ++i) {
    cout << 0;
  }
  for (i = 1; i < 10; ++i) {
    for (j = 0; j < b[i] - min(b[i], c[9 - i]); ++j) {
      cout << i;
      ++d[i];
    }
  }
  for (i = 0; i < 10; ++i) {
    for (j = 0; j < min(b[i], c[9 - i]); ++j) {
      cout << i;
      ++d[i];
    }
  }
  if (f) {
    cout << k;
    ++d[k];
  }
  for (i = 0; i < h; ++i) {
    cout << 0;
    ++d[0];
  }
  cout << endl;
  for (i = 0; i < c[0] - h - min(b[9], c[0]); ++i) {
    cout << 0;
  }
  for (i = 1; i < 10; ++i) {
    for (j = 0; j < c[i] - min(b[9 - i], c[i]); ++j) {
      cout << i;
      --d[i];
    }
  }
  for (i = 9; i >= 0; --i) {
    for (j = 0; j < min(b[9 - i], c[i]); ++j) {
      cout << i;
      --d[i];
    }
  }
  if (f) {
    cout << 10 - k;
    --d[10 - k];
  }
  for (i = 0; i < h; ++i) {
    cout << 0;
    --d[0];
  }
  cout << endl;
  return 0;
}

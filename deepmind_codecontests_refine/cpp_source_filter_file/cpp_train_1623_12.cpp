#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  short n, k, a = 0, max = 0, maxnow = 0, min = 0, minnow = 0, f = 1, b;
  cin >> n >> k >> s;
  for (; a < n; a++) {
    if (s[a] != 'Y') {
      maxnow++;
      if (max < maxnow) max++;
    } else
      maxnow = 0;
    if (s[a] == 'N') {
      minnow++;
      if (min < minnow) min++;
    } else
      minnow = 0;
  }
  if ((k < min) | (k > max)) {
    cout << "NO";
    return 0;
  }
  if ((k == min) | (k == max)) {
    cout << "YES";
    return 0;
  }
  for (a = 0; a < k; a++) {
    if (s[a] == 'Y') {
      f = 0;
      break;
    }
  }
  if (f & (s[a] != 'N')) {
    cout << "YES";
    return 0;
  }
  n -= k;
  f = 1;
  for (a = 1; a < n; a++) {
    for (b = a; b < a + k; b++) {
      if (s[a] == 'Y') {
        f = 0;
        break;
      }
    }
    if (f & (s[a - 1] != 'N') & (s[b] != 'N')) {
      cout << "YES";
      return 0;
    } else
      f = 1;
  }
  f = 1;
  for (a = n; a < n + k; a++) {
    if (s[a] == 'Y') {
      f = 0;
      break;
    }
  }
  if (f & (s[n - 1] != 'N')) {
    cout << "YES";
    return 0;
  } else
    cout << "NO";
  return 0;
}

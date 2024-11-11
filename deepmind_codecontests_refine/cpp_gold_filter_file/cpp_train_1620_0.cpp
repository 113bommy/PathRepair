#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == 0 && d == 0) {
    if (b + c > 1) {
      cout << "Impossible";
      return 0;
    }
    if (b == 0 && c == 0) {
      cout << 1;
      return 0;
    }
    if (b == 1) {
      cout << 0 << 1;
      return 0;
    }
    if (c == 1) {
      cout << 1 << 0;
      return 0;
    }
  }
  long long cnt0, cnt1;
  long long l = 0, r = 1000001;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (m * (m - 1) <= a * 2)
      l = m;
    else
      r = m;
  }
  if (l * (l - 1) != 2 * a) {
    cout << "Impossible";
    return 0;
  }
  cnt0 = l;
  l = 0, r = 1000001;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (m * (m - 1) <= d * 2)
      l = m;
    else
      r = m;
  }
  if (l * (l - 1) != 2 * d) {
    cout << "Impossible";
    return 0;
  }
  cnt1 = l;
  int solve = -1;
  if (cnt0 * cnt1 == b + c) {
    solve = 1;
  }
  if (a == 0 && solve == -1 && (cnt0 ^ 1) * cnt1 == b + c) {
    solve = 2;
    cnt0 ^= 1;
  }
  if (b == 0 && solve == -1 && (cnt1 ^ 1) * cnt0 == b + c) {
    solve = 3;
    cnt1 ^= 1;
  }
  if (solve == -1) {
    cout << "Impossible";
    return 0;
  }
  long long bb = cnt0 * cnt1;
  int first = 0;
  int kek = cnt0;
  while (bb != b) {
    if (bb - b >= cnt0) {
      first++, bb -= cnt0;
      continue;
    }
    kek = cnt0 - bb + b;
    break;
  }
  for (int i = 0; i < first; i++) {
    cout << 1;
    cnt1--;
  }
  for (int i = 0; i < kek; i++) {
    cnt0--;
    cout << 0;
  }
  if (cnt1 != 0) {
    cout << 1;
    cnt1--;
  }
  for (int i = 0; i < cnt0; i++) cout << 0;
  for (int i = 0; i < cnt1; i++) cout << 1;
  return 0;
}

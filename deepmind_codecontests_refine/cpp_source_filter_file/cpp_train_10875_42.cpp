#include <bits/stdc++.h>
using namespace std;
int ToInt(string& s, int len) {
  int r = 0;
  for (int i = 0, max_ = (len); i < max_; ++i) {
    r *= 10;
    r += s[i] - '0';
  }
  return r;
}
int GCD(int a, int b) { return b != 0 ? GCD(b, a % b) : a; }
int LCM(int a, int b) { return a * (b / GCD(a, b)); }
long long Pow(long long n, long long e) {
  if (e == 0) return 1;
  if (e == 1)
    return n;
  else if (e & 1) {
    long long t = Pow(n, e / 2);
    return n * t * t;
  } else {
    long long t = Pow(n, e / 2);
    return t * t;
  }
}
int m[51][51];
int main() {
  int N, M, t;
  scanf("%d %d", &N, &M);
  for (int i = 0, max_ = (N); i < max_; ++i)
    for (int j = 0, max_ = (M); j < max_; ++j) {
      cin >> t;
      if (t == 1) m[i][j] = 1;
      if (i > 0) m[i][j] += m[i - 1][j];
      if (j > 0) m[i][j] += m[i][j - 1];
      if (i > 0 && j > 0) m[i][j] -= m[i - 1][j - 1];
    }
  int A, B;
  scanf("%d %d", &A, &B);
  int min = numeric_limits<int>::max();
  for (int y = (A - 1), max_ = (N); y < max_; ++y)
    for (int x = (B - 1), max_ = (N); x < max_; ++x) {
      int cnt = m[y][x];
      if (y - A >= 0) cnt -= m[y - A][x];
      if (x - B >= 0) cnt -= m[y][x - B];
      if (y - A >= 0 && x - B >= 0) cnt += m[y - A][x - B];
      min = std::min(min, cnt);
    }
  for (int y = (B - 1), max_ = (N); y < max_; ++y)
    for (int x = (A - 1), max_ = (N); x < max_; ++x) {
      int cnt = m[y][x];
      if (y - B >= 0) cnt -= m[y - B][x];
      if (x - A >= 0) cnt -= m[y][x - A];
      if (y - B >= 0 && x - A >= 0) cnt += m[y - B][x - A];
      min = std::min(min, cnt);
    }
  printf("%d\n", min);
  return 0;
}

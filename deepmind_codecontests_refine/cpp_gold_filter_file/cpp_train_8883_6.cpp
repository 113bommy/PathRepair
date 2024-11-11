#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const int N = 1e5 + 5;
int x[7], ans[10], mx = 1e9;
string realans[4],
    s[7] = {"aaab", "aaba", "aabb", "abaa", "abab", "abba", "abbb"};
int a, b, c, d, e, f, g;
bool solve() {
  if ((a + b + e + f) % 2 != 0) return false;
  if ((a + c + d + f) % 2 != 0) return false;
  if ((b + c + d + e) % 2 != 0) return false;
  if ((a + c + e) % 2 != 0) return false;
  for (int i = 0; i <= 5e5; i++) {
    int A = i;
    int B = (d - c + b - e) / 2 + A;
    int C = (c - a + e) / 2 - A;
    int D = B - (b - a + f - e) / 2;
    int E = a - b + B + C - D;
    int F = e - A - C - D;
    int G = c - A - C - E;
    if (A < 0 || B < 0 || C < 0 || D < 0 || E < 0 || F < 0 || G < 0) continue;
    if (A + B + C + D + E + F + G < mx) {
      mx = A + B + C + D + E + F + G;
      ans[0] = A;
      ans[1] = B;
      ans[2] = C;
      ans[3] = D;
      ans[4] = E;
      ans[5] = F;
      ans[6] = G;
    }
  }
  if (mx == 1e9) return false;
  return true;
}
int main() {
  cin >> a >> b >> c >> d >> e >> f;
  if (solve()) {
    for (int i = 0; i < 7; i++)
      for (int k = 0; k < ans[i]; k++)
        for (int j = 0; j < 4; j++) realans[j] += s[i][j];
    cout << realans[0].size() << "\n";
    for (int i = 0; i < 4; i++) cout << realans[i] << "\n";
  } else
    cout << "-1\n";
  return 0;
}

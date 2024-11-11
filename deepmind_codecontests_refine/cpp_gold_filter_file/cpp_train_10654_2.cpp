#include <bits/stdc++.h>
using namespace std;
double eps = 1e-5;
bool good(double x) {
  if (abs(x - round(x)) <= eps)
    return true;
  else
    return false;
}
int main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.setf(ios::fixed);
  cout.precision(1);
  int ans[10];
  double S1, S2, S3, S4, S5, S6;
  cin >> S1 >> S2 >> S3 >> S4 >> S5 >> S6;
  double A = S1 - S4 + 2 * S6;
  double B = S1 - S4 + S6;
  double C = S4 - S6;
  int best = 1000000000;
  for (double x6 = 0; x6 <= 1000000; x6 += 1.0) {
    double x4 = (A - 2 * x6 + S3 - B - S2) / 2;
    double x7 = (S5 - C - 2 * x4) / 2;
    double x5 = S3 / 2 + x7 - B / 2;
    double x3 = S6 - x4 - x6 - x7;
    double x2 = S4 - x3 - x5 - x6;
    double x1 = S1 - x2 - x6 - x7;
    if (x1 + eps >= 0 && x2 + eps >= 0 && x3 + eps >= 0 && x4 + eps >= 0 &&
        x5 + eps >= 0 && x6 + eps >= 0 && x7 + eps >= 0 && good(x1) &&
        good(x2) && good(x3) && good(x4) && good(x5) && good(x6) && good(x7) &&
        best > (x1 + x2 + x3 + x4 + x5 + x6 + x7)) {
      best = (x1 + x2 + x3 + x4 + x5 + x6 + x7);
      ans[1] = x1;
      ans[2] = x2;
      ans[3] = x3;
      ans[4] = x4;
      ans[5] = x5;
      ans[6] = x6;
      ans[7] = x7;
    }
  }
  if (best == 1000000000) {
    cout << -1;
    return 0;
  }
  string s1;
  string s2;
  string s3;
  string s4;
  cout << best << "\n";
  for (int i = 0; i < ans[1]; i++) {
    s1 += 'a';
    s2 += 'b';
    s3 += 'b';
    s4 += 'b';
  }
  for (int i = 0; i < ans[2]; i++) {
    s1 += 'b';
    s2 += 'a';
    s3 += 'b';
    s4 += 'b';
  }
  for (int i = 0; i < ans[3]; i++) {
    s1 += 'b';
    s2 += 'b';
    s3 += 'a';
    s4 += 'b';
  }
  for (int i = 0; i < ans[4]; i++) {
    s1 += 'b';
    s2 += 'b';
    s3 += 'b';
    s4 += 'a';
  }
  for (int i = 0; i < ans[5]; i++) {
    s1 += 'a';
    s2 += 'a';
    s3 += 'b';
    s4 += 'b';
  }
  for (int i = 0; i < ans[6]; i++) {
    s1 += 'a';
    s2 += 'b';
    s3 += 'a';
    s4 += 'b';
  }
  for (int i = 0; i < ans[7]; i++) {
    s1 += 'a';
    s2 += 'b';
    s3 += 'b';
    s4 += 'a';
  }
  cout << s1 << "\n" << s2 << "\n" << s3 << "\n" << s4;
  return 0;
}

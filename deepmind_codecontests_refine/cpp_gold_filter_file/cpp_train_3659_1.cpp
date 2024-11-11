#include <bits/stdc++.h>
using namespace std;
int H, M, K;
long long calc2(int a, int k) {
  for (int i = 0; i < k - 1; ++i) {
    a /= 10;
  }
  return a;
}
int calcDigit(int a) {
  int ret = 0;
  while (a) {
    if (a % 10) ++ret;
    a /= 10;
  }
  return ret;
}
long long calc(int h, int m) {
  int d = calcDigit(M - 1);
  long long ret = calc2(h, K - d);
  ret += calc2(m, K) + h * calc2(M - 1, K);
  return ret;
}
int main() {
  cin >> H >> M >> K;
  int h1, m1, h2, m2;
  cin >> h1 >> m1 >> h2 >> m2;
  if (make_pair(h1, m1) <= make_pair(h2, m2))
    cout << calc(h2, m2) - calc(h1, m1) << endl;
  else
    cout << (calc(H - 1, M - 1) + ((calcDigit(H - 1) + calcDigit(M - 1)) >= K) -
             calc(h1, m1) + calc(h2, m2))
         << endl;
  return 0;
}

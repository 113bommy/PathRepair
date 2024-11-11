#include <bits/stdc++.h>
using namespace std;
int n, m;
long long fsu(long long w) {
  long long t = sqrt(w);
  if (t * t >= w) return t;
  return t + 1;
}
long long fsd(long long w) {
  long long t = sqrt(w);
  if (t * t <= w) return t;
  return t - 1;
}
long long L, R;
long long SQC(long long f, long long t) {
  L = f = fsu(f);
  R = t = fsd(t);
  return (t - f + 1);
}
int how[10000010];
int main() {
  long long ANS = 0, i, j;
  cin >> n >> m;
  for (long long I = 1; I <= n; ++I) {
    long long UP = min(I * I, (long long)m);
    ANS += 2 * (UP - SQC(I * I - UP, I * I - 1));
    ++how[I - R];
    --how[I - L + 1];
    ++how[I + L];
    --how[I + R + 1];
  }
  j = 0;
  for (i = 0; i <= 10000000; ++i) {
    j += how[i];
    if (j > 0) ++ANS;
  }
  cout << ANS << '\n';
  return 0;
}

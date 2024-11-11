#include <bits/stdc++.h>
using namespace std;
int r;
vector<long long> LenDou(81), afirst(81), alast(81), bfirst(81), blast(81);
long long min(long long a, long long b) {
  if (a > b)
    return b;
  else
    return a;
}
long long max(long long a, long long b) {
  if (a < b)
    return b;
  else
    return a;
}
void Init(long long x, int n, vector<long long>& first,
          vector<long long>& last) {
  if (n == 0) {
    first[0] = 0;
    last[0] = 0;
    return;
  }
  if (n == 1) {
    first[1] = (x == 2);
    last[1] = (x == 1);
    return;
  }
  if (x <= LenDou[n - 1]) {
    Init(x, n - 1, first, last);
    first[n] = min(first[n - 1], last[n - 1] + 2);
    last[n] = min(first[n - 1], last[n - 1]) + 1 + (n - 2 + 1) / 2;
  } else {
    Init(x - LenDou[n - 1], n - 2, first, last);
    first[n] = first[n - 2] + 1;
    last[n] = last[n - 2];
  }
}
long long dist(long long a, long long b, int n) {
  if (a == b) return 0;
  if (n <= 2) return 1;
  if (a <= LenDou[n - 1]) {
    if (b >= LenDou[n - 1] + 1)
      return min(afirst[n - 1], alast[n - 1]) + 1 + bfirst[n - 2];
    else
      return min(dist(a, b, n - 1), min(afirst[n - 1] + 2 + blast[n - 1],
                                        alast[n - 1] + 2 + bfirst[n - 1]));
  } else
    return dist(a - LenDou[n - 1], b - LenDou[n - 1], n - 2);
}
int main() {
  int t;
  cin >> t >> r;
  LenDou[0] = 1;
  LenDou[1] = 2;
  for (int i = 2; i <= 80; i++) LenDou[i] = LenDou[i - 1] + LenDou[i - 2];
  for (int ii = 1; ii <= t; ii++) {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
      long long c = a;
      a = b;
      b = a;
    }
    afirst.resize(81, 0);
    alast.resize(81, 0);
    bfirst.resize(81, 0);
    blast.resize(81, 0);
    Init(a, min(r, 80), afirst, alast);
    Init(b, min(r, 80), bfirst, blast);
    cout << dist(a, b, min(r, 80)) << endl;
  }
  return 0;
}

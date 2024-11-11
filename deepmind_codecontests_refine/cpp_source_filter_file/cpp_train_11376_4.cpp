#include <bits/stdc++.h>
using namespace std;
int T, N, L;
int A[100001];
int main() {
  cin >> T;
  while (T--) {
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    double p1 = 0;
    double p2 = L;
    int s1 = 1;
    int s2 = 1;
    int st = 0;
    int dr = N - 1;
    double time = 0;
    while (st <= dr) {
      double t1 = (A[st] - p1) / s1;
      double t2 = (p2 - A[dr]) / s2;
      if (fabs(t1 - t2) < 0.0000001) {
        p1 = A[st];
        p2 = A[dr];
        ++s1;
        ++s2;
        ++st;
        --dr;
        time += t1;
      } else if (t1 < t2) {
        p1 = A[st];
        p2 -= t1 * s2;
        ++s1;
        ++st;
        time += t1;
      } else {
        p2 = A[dr];
        p1 += t2 * s1;
        ++s2;
        --dr;
        time += t2;
      }
    }
    time += (p2 - p1) / (s1 + s2);
    printf("%.15lf\n", time);
  }
  return 0;
}

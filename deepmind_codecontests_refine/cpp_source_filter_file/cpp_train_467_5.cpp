#include <bits/stdc++.h>
using namespace std;
const int maxN = 5000;
int cant[10005], acum[10005];
int a[maxN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int k = 0; k < n; ++k) {
      if (i != k) {
        cant[a[i] - a[k] + maxN]++;
        acum[a[i] - a[k] + maxN]++;
      }
    }
  }
  for (int i = 10000; i >= 0; --i) {
    acum[i] += acum[i + 1];
  }
  long long answer = 0;
  for (int p1 = -maxN; p1 < 0; p1++) {
    for (int p2 = -maxN; p2 < 0; p2++) {
      int val = -(p1 + p2);
      val++;
      if (val < 10005) {
        long long tmp =
            (long long)cant[p1 + maxN] * cant[p2 + maxN] * acum[val + maxN];
        answer += tmp;
        assert(answer >= 0 && answer < 1e19);
      }
    }
  }
  double s = answer;
  s *= 8;
  s /= (n * (n - 1));
  s /= (n * (n - 1));
  s /= (n * (n - 1));
  printf("%.15f\n", (double)s);
  return 0;
}

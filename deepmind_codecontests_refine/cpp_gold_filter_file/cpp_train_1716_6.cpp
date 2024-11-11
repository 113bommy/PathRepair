#include <bits/stdc++.h>
using namespace std;
void solve(long long C, long long H1, long long H2, long long W1,
           long long W2) {
  long long ii, jj, ans = 0, w;
  for (long long i = 0; i < 1000; i++) {
    w = C - W1 * i;
    if (w < 0) {
      break;
    } else {
      long long j = w / W2;
      long long H = H1 * i + H2 * j;
      if (H > ans) {
        ans = H;
        ii = i;
        jj = j;
      }
    }
  }
  printf("%I64d | %I64d | %I64d | %lf %lf\n", ii, jj, ans, (H1 + 0.0) / H2,
         (W1 + 0.0) / W2);
}
int main() {
  long long w, C, H1, H2, W1, W2, j, i;
  cin >> C >> H1 >> H2 >> W1 >> W2;
  i = C / W1;
  j = C / W2;
  long long d = 25000;
  long long answer = 0;
  long long n = 0;
  for (long long ii = max(n, i - d); ii <= i + d; ii++) {
    w = C - W1 * ii;
    if (w < 0)
      continue;
    else {
      long long jj = w / W2;
      long long H = H1 * ii + H2 * jj;
      answer = max(answer, H);
    }
  }
  for (long long jj = max(n, j - d); jj <= j + d; jj++) {
    w = C - W2 * jj;
    if (w < 0)
      continue;
    else {
      long long ii = w / W1;
      long long H = H1 * ii + H2 * jj;
      answer = max(answer, H);
    }
  }
  cout << answer;
  return 0;
}

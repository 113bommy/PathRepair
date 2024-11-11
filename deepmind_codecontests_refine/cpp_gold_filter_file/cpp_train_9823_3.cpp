#include <bits/stdc++.h>
using namespace std;
int sign[100];
int lg(long long M) {
  int cnt = 0;
  while (M > 0) cnt++, M /= 2;
  return cnt;
}
long long func(long long M) {
  int cycle, repeat, i;
  long long ans = 0;
  for (cycle = 1; cycle <= 60; cycle++)
    for (repeat = 2; cycle * repeat <= 60; repeat++) {
      long long sum = 0, high;
      for ((i) = 0; (i) < (int)(repeat); (i)++) sum += (1ll << (i * cycle));
      int K = lg(M);
      long long two = (1ll << cycle);
      if (cycle * repeat > K) continue;
      if (cycle * repeat == K)
        high = M / sum;
      else
        high = two - 1;
      long long low = two / 2;
      if (low <= high) {
        ans += (high - low + 1) * -sign[repeat];
      }
    }
  return ans;
}
int main(void) {
  int i, j;
  sign[1] = 1;
  for (i = 1; i < 100; i++)
    for (j = 2 * i; j < 100; j += i) sign[j] -= sign[i];
  long long L, R;
  cin >> L >> R;
  long long ans = func(R) - func(L - 1);
  cout << ans << endl;
  return 0;
}

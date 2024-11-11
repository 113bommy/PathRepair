#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795029L;
int msqrt(long long n) { return n < 0 ? -1 : (int)floor(sqrtf(n)); }
int Msqrt(long long n) { return (int)ceil(sqrtf(n)); }
long long irr(long long n) { return n - msqrt(n); }
bool solve(int testNumber) {
  int n, m;
  if (scanf("%d %d", &n, &m) == EOF) return false;
  long long ans = 0;
  const int N = 10000000;
  vector<int> vet(2 * N);
  vector<int>::iterator M = vet.begin() + N;
  for (int b = 1; b <= n; b++) {
    int c1 = 1, c2 = (int)min((long long)m, (long long)b * b);
    long long d1 = (long long)b * b - c2, d2 = (long long)b * b - c1;
    ans += 2 * (irr(d2) - irr(d1 - 1));
    int x = -b - msqrt(d2), y = -b - Msqrt(d1);
    M[x]++, M[y + 1]--;
    x = -b + Msqrt(d1), y = -b + msqrt(d2);
    M[x]++, M[y + 1]--;
    if (c2 == (long long)b * b) M[-b]--, M[-b + 1]++;
  }
  int sum = 0, from;
  for (int i = 0; i < 2 * N; i++) {
    if (!sum) {
      sum += vet[i];
      from = i;
    } else {
      sum += vet[i];
      if (!sum) ans += i - from;
    }
  }
  printf("%lld\n", ans);
  return true;
}
int main() {
  for (int i = 1; solve(i); i++)
    ;
  return 0;
}

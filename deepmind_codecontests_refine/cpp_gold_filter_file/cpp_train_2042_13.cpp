#include <bits/stdc++.h>
using namespace std;
const int N = 3234567;
long long n, x, y;
int primes[N];
vector<int> P;
long long s[N];
long long c[N];
int main() {
  fill(primes, primes + N, 1);
  for (int i = 2; i < N; i++) {
    if (primes[i]) {
      for (int j = i + i; j < N; j += i) {
        primes[j] = 0;
      }
      P.push_back(i);
    }
  }
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    s[a] += a;
    c[a] += 1;
  }
  for (int i = 1; i < N; i++) {
    s[i] += s[i - 1];
    c[i] += c[i - 1];
  }
  int D = (x / y);
  long long ans = 1LL * x * n;
  for (int p : P) {
    long long got = 0;
    long long sum = 0;
    int d = min(D, p - 1);
    for (int i = p; i < N; i += p) {
      got += c[i] - c[i - d - 1];
      sum += ((c[i] - c[i - d - 1]) * i - (s[i] - s[i - d - 1])) * y;
    }
    sum += (n - got) * x;
    ans = min(ans, sum);
  }
  printf("%lld\n", ans);
  return 0;
}

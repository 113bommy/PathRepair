#include <bits/stdc++.h>
using namespace std;
const long long M = 2e6 + 5;
long long visit[M], prime[M];
void sieve(long long s) {
  for (long long i = s; i <= 2e6; i += s) visit[i] = 1;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, x, flag = 0, con = 2;
  cin >> n;
  long long a[n];
  for (long long i = 2; i <= 2e6; i++) {
    if (prime[i] == 0)
      for (long long j = i; j <= 2e6; j += i) {
        if (prime[j] == 0) prime[j] = i;
      }
  }
  for (long long i = 0; i < n; i++) {
    cin >> x;
    if (flag == 0) {
      long long t = x;
      while (prime[t]) {
        if (visit[prime[t]]) flag = 1;
        t /= prime[t];
      }
      while (visit[x]) x++;
      t = x;
      while (prime[t]) {
        if (visit[prime[t]] == 0) {
          sieve(prime[t]);
        }
        t /= prime[t];
      }
      a[i] = x;
    } else {
      while (visit[con]) con++;
      long long t = con;
      while (prime[t]) {
        if (visit[prime[t]] == 0) {
          sieve(prime[t]);
        }
        t /= prime[t];
      }
      a[i] = con;
    }
  }
  for (long long i = 0; i < n; i++) cout << a[i] << " ";
}

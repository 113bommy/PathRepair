#include <bits/stdc++.h>
using namespace std;
int dp[1000000];
int v(int n) {
  int N = n;
  if (dp[n] != -1) return dp[N];
  map<int, int> res;
  while (n % 2 == 0) {
    n /= 2;
    res[2]++;
  }
  int c = 3;
  while (c <= sqrt(double(n)) + 1)
    if (n % c == 0) {
      n /= c;
      res[c]++;
    } else
      c += 2;
  if (n > 1) res[n]++;
  long long aux = 1;
  for (map<int, int>::iterator i = res.begin(); i != res.end(); ++i) {
    aux *= ((i->second) + 1);
  }
  return dp[N] = aux;
}
void init() {
  dp[0] = -1;
  dp[1] = 1;
  for (int k = 2; k < 1000000; ++k) dp[k] = -1;
}
int main() {
  int a, b, c, i, j, k;
  long long sum;
  init();
  while (scanf("%d %d %d", &a, &b, &c) == 3) {
    sum = 0;
    for (i = 1; i <= a; ++i) {
      for (j = 1; j <= b; ++j) {
        for (k = 1; k <= c; ++k) {
          sum += v(i * j * k);
        }
      }
    }
    cout << sum % (1 << 30) << endl;
  }
  return 0;
}

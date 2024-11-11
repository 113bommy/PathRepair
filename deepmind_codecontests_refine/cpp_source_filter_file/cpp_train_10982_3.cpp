#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1003;
int prime[MAXN];
int initPrime(int max) {
  bool isPrime[MAXN] = {false};
  int p = 0;
  for (int i = 2; i < max; i++) {
    if (!isPrime[i]) {
      prime[p] = i;
      p++;
      for (int j = i + i; j <= max; j += i) {
        isPrime[j] = true;
      }
    }
  }
  return p;
}
int main() {
  int n;
  cin >> n;
  int m = initPrime(n);
  int k = 0;
  int ans[MAXN];
  for (int i = 0; i < m; i++) {
    int t = prime[i];
    for (int j = t; j <= n; j *= t) {
      ans[k] = j;
      k++;
    }
  }
  cout << k << endl;
  for (int i = 0; i < k; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}

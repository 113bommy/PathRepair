#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
const int maxn = 2e5 + 7;
int n, prime[1000005], a[200005], tot;
void getPrime(int N) {
  for (int i = 1; i <= N; i++) prime[i] = 1;
  for (int i = 2; i <= N; i++) {
    if (prime[i]) {
      prime[tot++] = i;
    }
    for (int j = 0; j < tot && prime[j] * i <= N; j++) {
      prime[i * prime[j]] = 0;
      if (i % prime[j] == 0) break;
    }
  }
}
int main() {
  cin >> n;
  getPrime(1e6);
  int cnt1 = 0, cnt2 = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 1)
      cnt1++;
    else
      cnt2++;
  }
  if (cnt2) {
    cout << 2;
    cnt2--;
  } else {
    cout << 1;
    for (int i = 2; i <= cnt1; i++) cout << " " << 1;
    cout << endl;
    return 0;
  }
  for (int i = 1; i < tot; i++) {
    int x = prime[i] - prime[i - 1];
    int tmp1 = x / 2, tmp2 = x % 2;
    while (tmp1 && cnt2) {
      cout << " " << 2;
      cnt2--;
    }
    if (cnt2 == 0) {
      for (int i = 1; i <= cnt1; i++) cout << " " << 1;
      cout << endl;
      return 0;
    }
    if (tmp2 && cnt1) {
      cout << " " << 1;
      cnt1--;
    }
    if (cnt1 == 0) {
      for (int i = 1; i <= cnt2; i++) cout << " " << 2;
      cout << endl;
      return 0;
    }
  }
  return 0;
}

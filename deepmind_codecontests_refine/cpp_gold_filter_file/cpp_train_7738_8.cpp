#include <bits/stdc++.h>
using namespace std;
int p[1000 + 5];
int sum[1000 + 5];
void create_prime_array() {
  bool prime[1000 + 1];
  memset(prime, true, sizeof(prime));
  for (int i = 2; i * i <= 1000; i++) {
    if (prime[i] == true) {
      for (int j = i * 2; j <= 1000; j += i) {
        prime[j] = false;
      }
    }
  }
  int j = -1;
  for (int i = 2; i < 1000; i++) {
    if (prime[i]) {
      ++j;
      p[j] = i;
    }
  }
}
int is_prime(int x) {
  if (x == 2)
    return 1;
  else if (x < 2 || !(x & 1))
    return 0;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int main() {
  create_prime_array();
  int n, k, cnt = 0;
  cin >> n >> k;
  for (int i = 0; p[i] <= n; i++) {
    sum[i] = p[i] + p[i + 1] + 1;
  }
  for (int i = 0; sum[i] <= n; i++) {
    if (is_prime(sum[i]) == 1) cnt++;
  }
  if (cnt >= k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

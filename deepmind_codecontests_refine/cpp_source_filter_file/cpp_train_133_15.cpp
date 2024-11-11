#include <bits/stdc++.h>
using namespace std;
const int MAXP = 1000000;
int prime[MAXP];
bool is_prime[MAXP];
void prime_list() {
  memset(is_prime, true, sizeof(is_prime));
  for (int i = 2; i <= MAXP; i++) {
    if (is_prime[i]) prime[++prime[0]] = i;
    for (int j = 1, k; (j <= prime[0]) && (k = i * prime[j]) <= MAXP; j++) {
      is_prime[k] = false;
      if (i % prime[j] == 0) break;
    }
  }
}
int cnt[MAXP];
int main() {
  prime_list();
  long long n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= prime[0]; ++i) {
    while (n % prime[i] == 0) {
      ++cnt[i];
      n /= prime[i];
    }
  }
  if (n > 1) cnt[0]++;
  int sum = 0;
  for (int i = 1; i <= prime[0]; ++i) {
    sum += cnt[i];
  }
  sum += cnt[0];
  long long ans = 1;
  if (sum == 2)
    cout << 2 << endl;
  else {
    cout << 1 << endl;
    if (sum == 1)
      cout << 0 << endl;
    else {
      int x = 0;
      bool ok = 0;
      for (int i = 1; i <= prime[0]; ++i) {
        while (cnt[i] >= 1) {
          x++;
          cnt[i]--;
          ans *= prime[i];
          if (x >= 2) {
            ok = 1;
            break;
          }
        }
        if (ok) break;
      }
      cout << ans << endl;
    }
  }
}

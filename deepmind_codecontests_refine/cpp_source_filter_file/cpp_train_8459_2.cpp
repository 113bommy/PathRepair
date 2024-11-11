#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n;
bool is_prime[MAXN];
vector<int> primes;
void sieve(int n) {
  fill(is_prime + 2, is_prime + n, true);
  for (int i = 2; i <= n; i++) {
    if (is_prime[i]) primes.push_back(i);
    for (auto p : primes) {
      if (p * i > n) break;
      is_prime[p * i] = false;
      if (i % p == 0) break;
    }
  }
}
bool vis[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  if (n == 1) {
    cout << "C 1" << endl;
    cout.flush();
    return 0;
  }
  sieve(n);
  int left = n, ans = 1, sqrt_n = sqrt(n);
  bool min_prim_flag = false;
  for (int i = 0; i < primes.size(); i++) {
    int p = primes[i];
    cout << "B " << p << endl;
    cout.flush();
    int mul_cnt = 0, real_mul_cnt;
    cin >> real_mul_cnt;
    for (int i = p; i <= n; i += p) {
      if (!vis[i]) {
        vis[i] = true;
        left--;
        mul_cnt++;
      }
    }
    if (mul_cnt != real_mul_cnt) {
      int res;
      for (long long j = p; j <= n; j *= p) {
        cout << "A " << j << endl;
        cout.flush();
        cin >> res;
        if (res != 1) break;
        ans *= p;
      }
    }
    if (((i + 1) % sqrt_n == 0 || i == primes.size() - 1) && !min_prim_flag) {
      cout << "A 1" << endl;
      cout.flush();
      int res;
      cin >> res;
      if (res != left) {
        for (int j = i - sqrt_n + 1; j <= i; j++) {
          cout << "A " << primes[j] << endl;
          cout.flush();
          cin >> res;
          if (res == 1) {
            for (long long k = primes[j]; k <= n; k *= primes[j]) {
              cout << "A " << k << endl;
              cout.flush();
              cin >> res;
              if (res != 1) break;
              ans *= primes[j];
            }
            min_prim_flag = true;
            break;
          }
        }
      }
    }
  }
  cout << "C " << ans << endl;
  cout.flush();
  return 0;
}

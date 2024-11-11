#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const long long INF = 1e18;
const long double PI = 4 * atan((long double)1);
const int INFTY = 1e7;
long long N, M, T;
bool is_prime[200000];
void sieve() {
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= 200000; i++) {
    if (is_prime[i] && (long long)i * i <= 200000) {
      for (int j = i * i; j <= 200000; j += i) {
        is_prime[j] = false;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> M;
  sieve();
  long long second = 2 * (N - 2);
  int idx = second + 3;
  while (!is_prime[idx]) {
    idx++;
  }
  if (M > 1)
    cout << 2 << " " << idx << endl;
  else
    cout << 2 << " " << 2 << endl;
  cout << 1 << " " << N << " " << 2 << endl;
  M--;
  for (int i = 2; i <= N - 2; i++) {
    cout << 1 << " " << i << " " << 2 << endl;
    M--;
  }
  if (M > 0) cout << 1 << " " << N - 1 << " " << (idx - second) << endl;
  if (M > 0) M--;
  for (int i = 2; i <= N && M > 0; i++) {
    for (int j = i + 1; j <= N && M > 0; j++) {
      cout << i << " " << j << " " << idx + 1 << endl;
      M--;
    }
  }
}

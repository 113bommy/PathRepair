#include <bits/stdc++.h>
using namespace std;
int MAX = 1000000;
int MIN = -1000000;
int INF = 1000000000;
int x4[4] = {0, 1, 0, -1};
int y4[4] = {1, 0, -1, 0};
int x8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int y8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int i, j, k;
long long mod = 1000000009ll;
long long fast(long long B) {
  if (B == 0ll) return 1ll;
  if (B == 2ll) return 2ll;
  if (B % 2ll == 0ll) {
    long long temp = fast(B / 2ll) % mod;
    return (temp * temp) % mod;
  } else
    return (fast(B - 1ll) * 2ll) % mod;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long aman = ((n / k) * (k - 1ll));
  long long sisa = n % k;
  long long bisa = aman + sisa;
  if (m <= bisa)
    cout << m << endl;
  else {
    long long kali = m - bisa;
    long long a = k * 2ll;
    long long temp = (((fast(kali) + mod) - 1ll) * a) % mod;
    temp = (temp + (bisa - (kali * (k - 1ll)))) % mod;
    cout << temp << endl;
  }
  {
    fflush(stdin);
    getchar();
  };
  return 0;
}

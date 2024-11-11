#include <bits/stdc++.h>
using namespace std;
inline long long add(long long x, long long y) {
  x += y;
  if (x >= 1000000007) x -= 1000000007;
  return x;
}
inline long long sub(long long x, long long y) {
  x -= y;
  if (x < 0) x += 1000000007;
  return x;
}
inline long long mul(long long x, long long y) {
  return ((x % 1000000007) * (y % 1000000007)) % 1000000007;
}
inline long long pwr(long long a, long long b) {
  long long x = 1LL;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
bool CHK(long long n) {
  if (n == 1) return 0;
  if (n == 2 or n == 3) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (long long i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
vector<long long> v[10];
map<long long, long long> we, cnt;
void GEN() {
  v[0].push_back(0);
  we[0] = 0;
  cnt[0] = 1;
  v[1].push_back(1);
  v[1].push_back(2);
  v[1].push_back(3);
  v[1].push_back(4);
  v[1].push_back(5);
  v[1].push_back(6);
  v[1].push_back(7);
  v[1].push_back(8);
  v[1].push_back(9);
  v[1].push_back(0);
  we[1] = 45;
  cnt[1] = 10;
  v[2].push_back(2);
  v[2].push_back(4);
  v[2].push_back(6);
  v[2].push_back(8);
  v[2].push_back(0);
  we[2] = 20;
  cnt[2] = 5;
  v[3].push_back(3);
  v[3].push_back(6);
  v[3].push_back(9);
  v[3].push_back(2);
  v[3].push_back(5);
  v[3].push_back(8);
  v[3].push_back(1);
  v[3].push_back(4);
  v[3].push_back(7);
  v[3].push_back(0);
  we[3] = 45;
  cnt[3] = 10;
  v[4].push_back(4);
  v[4].push_back(8);
  v[4].push_back(2);
  v[4].push_back(6);
  v[4].push_back(0);
  we[4] = 20;
  cnt[4] = 5;
  v[5].push_back(5);
  v[5].push_back(0);
  we[5] = 5;
  cnt[5] = 2;
  v[6].push_back(6);
  v[6].push_back(2);
  v[6].push_back(8);
  v[6].push_back(4);
  v[6].push_back(0);
  we[6] = 20;
  cnt[6] = 2;
  v[7].push_back(7);
  v[7].push_back(4);
  v[7].push_back(1);
  v[7].push_back(8);
  v[7].push_back(5);
  v[7].push_back(2);
  v[7].push_back(9);
  v[7].push_back(6);
  v[7].push_back(3);
  v[7].push_back(0);
  we[7] = 45;
  cnt[7] = 10;
  v[8].push_back(8);
  v[8].push_back(6);
  v[8].push_back(4);
  v[8].push_back(2);
  v[8].push_back(0);
  we[8] = 20;
  cnt[8] = 5;
  v[9].push_back(9);
  v[9].push_back(8);
  v[9].push_back(7);
  v[9].push_back(6);
  v[9].push_back(5);
  v[9].push_back(4);
  v[9].push_back(3);
  v[9].push_back(2);
  v[9].push_back(1);
  v[9].push_back(0);
  we[9] = 45;
  cnt[9] = 10;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  GEN();
  long long q = 0;
  cin >> q;
  while (q--) {
    long long n = 0, m = 0;
    cin >> n >> m;
    long long d = n / m;
    m = m % 10;
    long long rem = d % cnt[m];
    long long p = d / cnt[m];
    long long res = p * we[m];
    for (long long i = 0; i < rem; i++) res += v[m][i];
    cout << res << "\n";
  }
  return 0;
}

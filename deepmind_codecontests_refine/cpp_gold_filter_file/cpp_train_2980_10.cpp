#include <bits/stdc++.h>
constexpr auto INF = 9223372036854775807;
using namespace std;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937 mt(seed);
int myrand(int mod) { return mt() % mod; }
inline long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int mod_power(long long int x, long long int y) {
  long long int res = 1;
  x = x % (long long int)998244353;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % (long long int)998244353;
    y = y >> 1;
    x = (x * x) % (long long int)998244353;
  }
  return res;
}
long long modInverse(long long n) {
  return mod_power(n, (long long int)998244353 - 2);
}
long long nCrModPFermat(long long n, long long int r) {
  if (r == 0) return 1;
  vector<long long int> fac(n + 1, 0);
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = (fac[i - 1] * i) % (long long int)998244353;
  return (fac[n] * modInverse(fac[r]) % (long long int)998244353 *
          modInverse(fac[n - r]) % (long long int)998244353) %
         (long long int)998244353;
}
bool isprime(long long int n) {
  if (n == 2) return true;
  if (n % 2 == 0 || n == 1) {
    return false;
  }
  for (long long int j = 3; j <= sqrt(n); j += 2) {
    if (n % j == 0) {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int k, a, b;
  cin >> k >> a >> b;
  a -= 1;
  b -= 1;
  long long int arr[3][3], brr[3][3];
  for (long long int i = 0; i < 3; i += 1) {
    for (long long int j = 0; j < 3; j += 1) {
      cin >> arr[i][j];
      arr[i][j] -= 1;
    }
  }
  for (long long int i = 0; i < 3; i += 1) {
    for (long long int j = 0; j < 3; j += 1) {
      cin >> brr[i][j];
      brr[i][j] -= 1;
    }
  }
  vector<vector<bool>> visited(3, vector<bool>(3, false));
  long long int x, y;
  x = a;
  y = b;
  vector<pair<long long int, long long int>> temp2;
  long long int cx = -1, cy = -1;
  while (1) {
    if (visited[x][y]) {
      cx = x;
      cy = y;
      break;
    }
    long long int temp = x;
    visited[x][y] = true;
    temp2.push_back({x, y});
    x = arr[x][y];
    y = brr[temp][y];
  }
  long long int ind = 0;
  while (temp2[ind] != make_pair(cx, cy)) {
    ind += 1;
  }
  vector<pair<long long int, long long int>> cycle;
  for (long long int i = ind; i < temp2.size(); i += 1) {
    cycle.push_back(temp2[i]);
  }
  vector<pair<long long int, long long int>> cnt(cycle.size() + 1, {0, 0});
  for (long long int i = 0; i < cycle.size(); i += 1) {
    long long int fir = cycle[i].first, sec = cycle[i].second;
    fir += 1;
    sec += 1;
    cnt[i + 1] = cnt[i];
    if (fir != sec) {
      if (fir * sec == 3) {
        if (fir == 1) {
          cnt[i + 1].first += 1;
        } else
          cnt[i + 1].second += 1;
      }
      if (fir * sec == 2) {
        if (fir == 2) {
          cnt[i + 1].first += 1;
        } else
          cnt[i + 1].second += 1;
      }
      if (fir * sec == 6) {
        if (fir == 3) {
          cnt[i + 1].first += 1;
        } else
          cnt[i + 1].second += 1;
      }
    }
  }
  long long int alice = 0, bob = 0;
  x = a, y = b;
  while ((k > 0) && ((cycle.size() == 0) || (make_pair(x, y) != cycle[0]))) {
    long long int fir = x, sec = y;
    fir += 1;
    sec += 1;
    if (fir != sec) {
      if (fir * sec == 3) {
        if (fir == 1) {
          alice += 1;
        } else
          bob += 1;
      }
      if (fir * sec == 2) {
        if (fir == 2) {
          alice += 1;
        } else
          bob += 1;
      }
      if (fir * sec == 6) {
        if (fir == 3) {
          alice += 1;
        } else
          bob += 1;
      }
    }
    k -= 1;
    long long int temp = x;
    x = arr[x][y];
    y = brr[temp][y];
  }
  long long int req = k / cycle.size();
  long long int left = k % cycle.size();
  alice += cnt[cycle.size()].first * req;
  bob += cnt[cycle.size()].second * req;
  alice += cnt[left].first;
  bob += cnt[left].second;
  cout << alice << " " << bob;
  return 0;
}

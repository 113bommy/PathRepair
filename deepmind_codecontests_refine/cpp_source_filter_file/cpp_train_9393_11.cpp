#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1e9 + 7;
const long long int N = 2e5 + 9;
long long int primes[6] = {1125899906842597, 1495921043, 1005985879,
                           1495921043,       1005985879, 1495921043};
vector<long long int> adj[N];
long long int parent[N];
long long int vis[N];
long long int level[N];
long long int dist[N];
long long int dp[N];
long long int arr[1000009];
long long int brr[1000009];
long long int crr[1000009];
long long int hashing[N];
long long int ar[509][509];
long long int br[509][509];
long long int cr[509][509];
long long int multiply(long long int a, long long int b) {
  return ((a % mod) * (b % mod)) % mod;
}
long long int add(long long int a, long long int b) {
  return ((a % mod) + (b % mod)) % mod;
}
long long int sub(long long int a, long long int b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = ((res % p) * (x % p)) % p;
    y = y >> 1;
    x = ((x % p) * (x % p)) % p;
  }
  return res;
}
long long int POWER(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res *= x;
    y = y >> 1;
    x *= x;
  }
  return res;
}
int main() {
  int start_s = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  vector<long long int> vect, vect1, vect2, vt, vct;
  vector<long long int>::iterator itt;
  set<long long int> st, stt, st1, st2;
  set<long long int>::iterator itr;
  map<long long int, long long int> mp, mp1, mp2, mpp;
  map<long long int, long long int>::iterator it;
  long long int i, j, k, n, m, q, t, a, d, b, c, l, r, e, idx, ind, index, u, v,
      x, y, z, h, sz, sz1, sz2, mid, len, tot;
  long long int res = 0, res1 = 0, res2 = 0, ans = 0, ans1 = 0, ans2 = 0,
                val = 0, val1 = 0, val2 = 0, rem = 0, diff = 0, cnt = 0,
                flag = 0, fl = 0, sum = 0, maxi = INT_MIN, mini = INT_MAX,
                total = 0;
  string str, str1, str2;
  char ch, ch1, ch2;
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1)
      cout << -1 << "\n";
    else {
      n--;
      while (n--) {
        cout << 7 << " ";
      }
      cout << 8 << "\n";
    }
  }
}

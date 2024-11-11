#include <bits/stdc++.h>
using namespace std;
const long long int maxn = 1e5 + 6;
const long long int MOD = 1e9 + 7;
vector<int> prim(1000005, 1);
int fact[maxn];
long long int binomialCoeff(long long int n, long long int k) {
  long long int res = 1;
  if (k > n - k) k = n - k;
  for (long long int i = 0; i < k; ++i) {
    res *= (n - i);
    res /= (i + 1);
  }
  return res;
}
bool isVowel(char ch) {
  if (ch == 'a' || ch == 'i' || ch == 'e' || ch == 'u' || ch == 'o') {
    return true;
  }
  return false;
}
long long int power(long long int x, long long int i, long long int mod) {
  long long int ans = 1;
  while (i > 0) {
    if (i & 1) ans = (ans * x) % mod;
    i >>= 1;
    x = (x * x) % mod;
  }
  return ans;
}
long long int modInverse(long long int x, long long int mod) {
  return power(x, mod - 2, mod);
}
int nCr(int n, int r) {
  if (n < r) {
    return 0;
  }
  return (((fact[n] * modInverse(fact[n - r], MOD)) % MOD) *
          modInverse(fact[r], MOD)) %
         MOD;
}
long long int power(int x, unsigned int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
void erath(int n) {
  prim[1] = 0;
  prim[0] = 0;
  prim[2] = 1;
  for (int i = 2; i * i <= n; i++) {
    if (prim[i]) {
      for (int j = i * i; j <= n; j += i) {
        prim[j] = 0;
      }
    }
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a / gcd(a, b)) * b;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long int n, m, k;
int getmid(int l, int r) { return (l + (r - l) / 2); }
struct segtree {
  int siz;
  vector<pair<long long int, long long int> > sums;
  void init(int n) {
    siz = 1;
    while (siz < n) siz *= 2;
    sums.assign(2 * siz, {LONG_MAX, 0});
  }
  void set(int i, int v, int cur, int l, int r) {
    if (r - l == 1) {
      sums[cur].first = v;
      sums[cur].second = 1;
      return;
    }
    int m = getmid(l, r);
    if (i < m) {
      set(i, v, 2 * cur + 1, l, m);
    } else
      set(i, v, 2 * cur + 2, m, r);
    sums[cur].first = min(sums[2 * cur + 1].first, sums[2 * cur + 2].first);
    if (sums[2 * cur + 1].first == sums[cur].first &&
        sums[2 * cur + 2].first == sums[cur].first) {
      sums[cur].second = sums[cur * 2 + 1].second + sums[cur * 2 + 2].second;
    } else if (sums[2 * cur + 1].first == sums[cur].first) {
      sums[cur].second = sums[cur * 2 + 1].second;
    } else {
      sums[cur].second = sums[cur * 2 + 2].second;
    }
  }
  void set(int i, int v) { set(i, v, 0, 0, siz); }
  pair<long long int, long long int> sum(int l, int r, int cur, int lx,
                                         int rx) {
    if (lx >= r || l >= rx) return {LONG_MAX, 0};
    if (lx >= l && rx <= r) return {sums[cur].first, sums[cur].second};
    int mid = getmid(lx, rx);
    pair<long long int, long long int> s1 = sum(l, r, 2 * cur + 1, lx, mid),
                                       s2 = sum(l, r, 2 * cur + 2, mid, rx);
    if (s1.first < s2.first) {
      return s1;
    } else if (s1.first > s2.first)
      return s2;
    else
      return {s1.first, s1.second + s2.second};
  }
  pair<long long int, long long int> sum(int l, int r) {
    return sum(l, r, 0, 0, siz);
  }
};
int nCrModp(int n, int r, int p) {
  if (r > n - r) r = n - r;
  int C[r + 1];
  memset(C, 0, sizeof(C));
  C[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = min(i, r); j > 0; j--) C[j] = (C[j] + C[j - 1]) % p;
  }
  return C[r];
}
void ans(int top) {
  cin >> n >> k;
  long long int h[n], mx = INT_MIN, mn = INT_MAX;
  vector<long long int> fin(200002, 0);
  for (int i = 0; i < n; i++) {
    cin >> h[i];
    if (h[i] > 0) fin[1] += 1;
    if (h[i] > 0) fin[h[i] + 1] -= 1;
    mx = max(mx, h[i]);
    mn = min(mn, h[i]);
  }
  for (int i = 1; i < mx + 1; i++) {
    fin[i] += fin[i - 1];
  }
  int i = mx, ans = 0;
  while (i > mn) {
    int j = i, sum = 0;
    while (sum + fin[j] <= k) {
      sum += fin[j];
      j--;
    }
    i = j;
    ans++;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t = 1, co = 1;
  while (t--) {
    ans(co);
    co++;
  }
  return 0;
}

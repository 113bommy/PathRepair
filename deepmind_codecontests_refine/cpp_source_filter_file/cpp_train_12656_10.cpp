#include <bits/stdc++.h>
using namespace std;
inline bool isPowerOfTwo(int x) { return (x != 0 && (x & (x - 1)) == 0); }
double pi = 3.141592653589793238462643;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
inline int add(int a, int b, int m = 1000000007) {
  a += b;
  if (a >= m) a -= m;
  return a;
}
inline int mul(int a, int b, int m = 1000000007) {
  return (int)(((long long)a * (long long)b) % m);
}
inline bool ispalin(string &str) {
  int n = str.length();
  for (int i = 0; i < n / 2; i++)
    if (str[i] != str[n - i - 1]) return false;
  return true;
}
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % 1000000007;
    }
    base *= base;
    base %= 1000000007;
    pow /= 2;
  }
  return ans;
}
void swapp(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
long long inv(long long x) { return expo(x, 1000000007 - 2); }
int expFactor(int n, int p) {
  int x = p;
  int exponent = 0;
  while ((n / x) > 0) {
    exponent += n / x;
    x *= p;
  }
  return exponent;
}
inline int countsetbit(int n) {
  unsigned int count = 0;
  while (n) {
    n &= (n - 1);
    count++;
  }
  return count;
}
inline int abs(int x) {
  if (x < 0) return -x;
  return x;
}
bool isPal(string ss) {
  int len = ss.length();
  for (int i = 0; i < len / 2; i++) {
    int comp = len - i - 1;
    if (ss[i] != ss[comp]) return false;
  }
  return true;
}
long long _sieve_size;
bitset<10000010> bs;
vector<int> primes;
void sieve(long long upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (long long i = 2; i <= _sieve_size; i++)
    if (bs[i]) {
      for (long long j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
      primes.push_back((int)i);
    }
}
bool isPrime(long long N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n;
int p[N], t[N];
int x[N], arr[N];
int segtree[N];
int lazy[N];
void push(int l, int r, int node) {
  if (lazy[node]) {
    segtree[node] += lazy[node];
    if (l != r) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }
}
void update(int l, int r, int node, int ql, int qr, int val) {
  push(l, r, node);
  if (l > qr || r < ql) {
    return;
  }
  if (l >= ql && r <= qr) {
    lazy[node] = val;
    push(l, r, node);
    return;
  }
  int mid = (l + r) / 2;
  update(l, mid, 2 * node, ql, qr, val);
  update(mid + 1, r, 2 * node + 1, ql, qr, val);
  segtree[node] = max(segtree[2 * node], segtree[2 * node + 1]);
}
int query(int l, int r, int node) {
  push(l, r, node);
  if (segtree[node] <= 0) {
    return -1;
  }
  if (l == r) {
    return arr[l];
  }
  int mid = (l + r) / 2;
  int ret = query(mid + 1, r, 2 * node + 1);
  if (ret == -1) {
    ret = query(l, mid, 2 * node);
  }
  return ret;
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    cin >> p[i] >> t[i];
    if (t[i] == 0) {
      update(1, n, 1, 1, p[i], -1);
    } else {
      cin >> x[i];
      arr[p[i]] = x[i];
      update(1, n, 1, 1, p[i], 1);
    }
    cout << query(1, n, 1) << endl;
  }
}

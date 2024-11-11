#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fact(long long j) {
  long long a = 1;
  for (long long i = 1; i <= j; i++) a *= i;
  return a;
}
long long pw(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2)
    return pw(a, b - 1) * a;
  else {
    long long x = pw(a, b / 2);
    return x * x;
  }
}
long long sum2(long long c) {
  long long s = 0;
  while (c != 0) {
    s += (c % 10) * (c % 10);
    c /= 10;
  }
  return s;
}
vector<int> merge(const vector<int> &a, const vector<int> &b) {
  long long p1 = 0, p2 = 0;
  vector<int> c;
  for (; p1 < a.size() && p2 < b.size();)
    if (a[p1] == b[p2]) {
      c.push_back(a[p1]);
      p1++;
      p2++;
    } else if (a[p1] < b[p2])
      p1++;
    else
      p2++;
  return c;
}
bool prime(long long a) {
  if (a == 0 || a == 1) return false;
  for (int i = 2; i <= sqrt(a); i++)
    if (a % i == 0) return false;
  return true;
}
long long C(long long n, long long k) {
  vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 1));
  for (int i = 0; i < (n + 1); i++) {
    for (int j = 1; j < i; j++) {
      dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
    }
  }
  return dp[n][k];
}
struct st {
  int h, m, s;
};
bool operator<(st A, st B) {
  return (A.h < B.h || A.h == B.h && A.m < B.m ||
          A.h == B.h && A.m == B.m && A.s < B.s);
}
bool cmp(long long a, long long b) {
  if (a % 10 < b % 10) return true;
  if (a % 10 > b % 10) return false;
  if (a % 10 == b % 10) {
    return (a < b);
  }
}
long long phi(long long n) {
  long long ans = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      ans -= ans / i;
    }
  if (n > 1) ans -= ans / n;
  return ans;
}
vector<long long> rech(200005, 1);
void reh() {
  rech[0] = 0;
  rech[1] = 0;
  for (long long i = 2; i < 100000; i++)
    for (long long j = i * i; j < 100000; j += i)
      if (rech[j]) rech[j] = 0;
}
struct Node {
  long long i, mx;
};
Node tr[4 * 1000000 + 10];
void build(vector<long long> &a, long long v, long long l, long long r) {
  if (l == r)
    tr[v].i = l, tr[v].mx = a[l];
  else {
    long long m = (l + r) / 2;
    build(a, 2 * v, l, m);
    build(a, 2 * v + 1, m + 1, r);
    if (tr[2 * v].mx >= tr[2 * v + 1].mx)
      tr[v].i = tr[2 * v].i, tr[v].mx = tr[2 * v].mx;
    else
      tr[v].i = tr[2 * v + 1].i, tr[v].mx = tr[2 * v + 1].mx;
  }
}
Node find(long long x, long long y, long long v, long long l, long long r) {
  if (x == l && y == r) return tr[v];
  long long m = (l + r) / 2;
  if (y <= m)
    return find(x, y, 2 * v, l, m);
  else if (x > m)
    return find(x, y, 2 * v + 1, m + 1, r);
  else {
    Node a, b, c;
    a = find(x, m, 2 * v, l, m);
    b = find(m + 1, y, 2 * v + 1, m + 1, r);
    if (a.mx >= b.mx)
      c.i = a.i, c.mx = a.mx;
    else
      c.i = b.i, c.mx = b.mx;
    return c;
  }
}
void update(long long i, long long x, long long v, long long l, long long r) {
  if (l == r) {
    if (tr[v].mx != 0)
      tr[v].mx = x;
    else
      return;
  } else {
    long long m = (l + r) / 2;
    if (i <= m)
      update(i, x, 2 * v, l, m);
    else
      update(i, x, 2 * v + 1, m + 1, r);
    if (tr[2 * v].mx >= tr[2 * v + 1].mx)
      tr[v].i = tr[2 * v].i, tr[v].mx = tr[2 * v].mx;
    else
      tr[v].i = tr[2 * v + 1].i, tr[v].mx = tr[2 * v + 1].mx;
  }
}
struct cir {
  long long x, y, r;
};
int main() {
  long long n, k, t;
  cin >> n >> k >> t;
  if (t < k)
    cout << t << endl;
  else if (t > n)
    cout << k - t + n << endl;
  else
    cout << k << endl;
  return 0;
}

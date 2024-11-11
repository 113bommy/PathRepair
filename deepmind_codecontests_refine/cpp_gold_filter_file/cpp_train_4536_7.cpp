#include <bits/stdc++.h>
using namespace std;
const long long MAXN = (long long)((1e5) + 100);
long long cuberoot(long long x) {
  long long lo = 1, hi = min(2000000ll, x);
  while (hi - lo > 1) {
    long long mid = (lo + hi) / 2;
    if (mid * mid * mid < x) {
      lo = mid;
    } else
      hi = mid;
  }
  if (hi * hi * hi <= x)
    return hi;
  else
    return lo;
}
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
long long XX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
long long YY[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const long long N = (long long)(1 * 1e6 + 10);
bool comp(pair<long long, pair<long long, long long>> p1,
          pair<long long, pair<long long, long long>> p2) {
  if (p1.first > p2.first)
    return true;
  else if (p1.second == p2.second) {
    if (p1.second.first < p2.second.first) return true;
  }
  return false;
}
long long fact(long long n);
long long ncr(long long n, long long r) {
  return fact(n) / (fact(r) * fact(n - r));
}
long long fact(long long n) {
  long long res = 1;
  for (long long i = 2; i <= n; i++) res = res * i;
  return res % 1000000007;
}
const long long a = 1000000000;
long long nCr(long long n, long long r) {
  long long fac1 = 1, fac2 = 1, fac;
  for (long long i = r; i >= 1; i--, n--) {
    fac1 = fac1 * n;
    if (fac1 % i == 0)
      fac1 = fac1 / i;
    else
      fac2 = fac2 * i;
  }
  fac = fac1 / fac2;
  return fac % a;
}
long long knapsack(long long val[], long long wt[], long long W, long long n) {
  if (n == 0 || W == 0) return 0;
  if (wt[n - 1] > W)
    return knapsack(val, wt, W, n - 1);
  else
    return max(val[n - 1] + knapsack(val, wt, W - wt[n - 1], n - 1),
               knapsack(val, wt, W, n - 1));
}
const long long m = 1000000007;
long long tree[10000];
void build(long long node, long long tl, long long tr, long long arr[]) {
  if (tr == tl) {
    tree[node] = arr[tl];
    return;
  }
  long long mid = (tr + tl) / 2;
  build(2 * node, tl, mid, arr);
  build(2 * node + 1, mid + 1, tr, arr);
  tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long query_sum(long long node, long long tl, long long tr, long long l,
                    long long r) {
  if (l > tr || r < tl) return 0;
  if (tl >= l && tr <= r) return tree[node];
  long long mid = (tl + tr) / 2;
  long long p1 = query_sum(2 * node, tl, mid, l, r);
  long long p2 = query_sum(2 * node + 1, mid + 1, tr, l, r);
  return p1 + p2;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
signed main() {
  long long n, k, p;
  cin >> n;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    cin >> p;
    v.push_back(p);
  }
  if (n == 1) {
    if (v[0] % 2 != 0)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  } else if (n == 2) {
    if (v[1] % 2 == 0 && v[0] % 2 != 0)
      cout << "NO"
           << "\n";
    else
      cout << "YES"
           << "\n";
  } else {
    for (long long i = 0; i < n - 1; i++) {
      if (v[i] % 2 != 0 && v[i + 1] != 0) {
        v[i]--;
        v[i + 1]--;
      } else if (v[i] % 2 != 0 && v[i + 1] == 0) {
        cout << "NO"
             << "\n";
        return 0;
      }
    }
    for (long long i = 0; i < n; i++) {
      if (v[i] % 2 != 0) {
        cout << "NO"
             << "\n";
        return 0;
      }
    }
    cout << "YES"
         << "\n";
  }
}

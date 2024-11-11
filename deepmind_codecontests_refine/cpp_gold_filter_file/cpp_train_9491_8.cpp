#include <bits/stdc++.h>
using namespace std;
long long int par[100005], x[1000005], y[1000005], w[1000005], pos[1000005],
    sizee[100005];
long long int fact(long long int n) {
  if (n == 1 || n == 0) return 1;
  return n * fact(n - 1);
}
int isPrime(long long int n) {
  long long int i, j;
  for (i = 2; i < sqrt(n) + 1; i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long int modexpo(long long int x, long long int p) {
  long long int res = 1;
  x = x % 1000000007;
  while (p) {
    if (p % 2) res = res * x;
    p >>= 1;
    x = x * x % 1000000007;
    res %= 1000000007;
  }
  return res;
}
long long int binSearch(long long int a[], long long int l, long long int h,
                        long long int x) {
  long long int c = -1;
  while (l <= h) {
    long long int m = (l + h) / 2;
    if (a[m] >= x) {
      c = m;
      h = m - 1;
    } else
      l = m + 1;
  }
  return c;
}
void pairsort(long long int a[], long long int b[], long long int n) {
  pair<long long int, long long int> pairt[n];
  for (long long int i = 0; i < n; i++) {
    pairt[i].first = a[i];
    pairt[i].second = b[i];
  }
  sort(pairt, pairt + n);
  for (long long int i = 0; i < n; i++) {
    a[i] = pairt[i].first;
    b[i] = pairt[i].second;
  }
}
long long int mulmod(long long int a, long long int b) {
  long long int res = 0;
  a = a % 1000000007;
  while (b > 0) {
    if (b % 2 == 1) res = (res + a) % 1000000007;
    a = (a * 2) % 1000000007;
    b /= 2;
  }
  return res % 1000000007;
}
void init(long long int n) {
  long long int i;
  for (i = 0; i < n + 1; i++) {
    par[i] = i;
    sizee[i] = 1;
  }
}
long long int root(long long int x) {
  while (x != par[x]) {
    par[x] = par[par[x]];
    x = par[x];
  }
  return x;
}
void Union(long long int x, long long int y) {
  long long int ra = root(x);
  long long int rb = root(y);
  if (ra == rb) return;
  if (sizee[ra] < sizee[rb]) {
    par[ra] = rb;
    sizee[rb] += sizee[ra];
  } else {
    par[rb] = ra;
    sizee[ra] += sizee[rb];
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, t, m, k = 1, i, j, l, f = 0, h = 0, sum = 0, ans = 0, s, b;
  cin >> n >> m;
  init(n + 1);
  for (i = 0; i < m; i++) {
    cin >> x[i] >> y[i] >> w[i];
    pos[i] = i;
  }
  pairsort(w, pos, m);
  k = 0;
  if (m == n - 1) {
    cout << 1000000000;
    return 0;
  }
  for (i = 0; i < m; i++) {
    if (pos[i] != 0 && root(x[pos[i]]) != root(y[pos[i]])) {
      Union(x[pos[i]], y[pos[i]]);
      sum += w[i];
      k++;
      if (k == n - 1) break;
    }
  }
  long long int sum1 = 0;
  init(n + 1);
  Union(x[0], y[0]);
  for (i = 0; i < m; i++) {
    if (pos[i] == 0) j = i;
  }
  sum1 += w[j];
  k = 1;
  for (i = 0; i < m; i++) {
    if (pos[i] != 0 && root(x[pos[i]]) != root(y[pos[i]])) {
      Union(x[pos[i]], y[pos[i]]);
      sum1 += w[i];
      k++;
      if (k == n - 1) break;
    }
  }
  if (sum1 > sum)
    cout << w[j] - (sum1 - sum);
  else
    cout << sum - sum1 + w[j];
  return 0;
}

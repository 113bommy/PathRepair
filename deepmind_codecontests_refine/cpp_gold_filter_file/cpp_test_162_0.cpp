#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979323846;
long long int n, m = 0, x, sum, k, p, u = 0, t1 = 1;
string s, z;
vector<long long int> P((10000005));
void sieve() {
  for (long long int i = 2; i < (10000005); i++)
    if (!P[i])
      for (long long int j = i * i; j < (10000005); j += i) P[j] = i;
}
long long int raised(long long int x, long long int v, long long int mod) {
  if (v == 0) return 1 % mod;
  if (v % 2 == 1) return (x * raised(x, v - 1, mod)) % mod;
  long long int r = raised(x, v / 2, mod);
  return (r * r) % mod;
}
long long int N = 10002;
vector<long long int> divi[10002];
void prec() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divi[j].push_back(i);
    }
  }
}
bool comp(pair<long long int, long long int> a,
          pair<long long int, long long int> b) {
  return a.second - a.first < b.second - b.first;
}
long long int allotNumberToTime(string a, string b) {
  long long int x = 0, hh = 0, mm = 0;
  hh = 10 * (a[0] - '0') + a[1] - '0';
  hh %= 12;
  mm = 10 * (a[0 + 3] - '0') + a[1 + 3] - '0';
  if (b[0] == 'P') hh += 12;
  return x = 60 * hh + mm;
}
long long int queryForSegmentTree(long long int l, long long int r,
                                  vector<long long int>& v, long long int f) {
  long long int h = f ? INT_MIN : INT_MAX;
  while (l <= r) {
    if (l % 2 == 1) {
      h = f ? max(h, v[l]) : min(h, v[l]);
      l++;
    }
    if (r % 2 == 0) {
      h = f ? max(h, v[r]) : min(h, v[r]);
      r--;
    }
    l /= 2;
    r /= 2;
  }
  return h;
}
pair<long long int, long long int> dfs(vector<long long int> v[],
                                       long long int a[], long long int x) {
  if ((long long int)((v[x]).size()) == 0) return make_pair(1ll, 1ll);
  long long int c = 0, d = 0, l = 0, b = 0;
  vector<pair<long long int, long long int>> u;
  for (long long int i = 0; i < v[x].size(); i++) {
    pair<long long int, long long int> y = dfs(v, a, v[x][i]);
    b += y.second - y.first + 1;
    l += y.second;
    u.push_back(y);
    c = max(c, y.first);
  }
  for (long long int i = 0; i < (long long int)((u).size()); i++) {
    d = max(d, u[i].first + l - u[i].second);
  }
  if (a[x - 1]) return make_pair(d, l);
  return make_pair(l - b + 1, l);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  t1 = 1;
  cin >> t1;
  while (t1--) {
    cin >> n;
    long long int b[n];
    for (long long int i = 0ll; i < n; i++) cin >> b[i];
    long long int l = 0, r = 1e15;
    while (l < r) {
      long long int mid = (l + r + 1) / 2;
      bool ok = 1;
      long long int a[n];
      for (long long int i = 0ll; i < n; i++) a[i] = b[i];
      for (long long int i = n - 1; i >= 0; i--) {
        if (a[i] < mid)
          ok = 0;
        else {
          long long int f = min((a[i] - mid) / 3, b[i] / 3);
          a[i] -= 3 * f;
          if (i >= 2) a[i - 1] += f;
          if (i - 2 >= 0) a[i - 2] += 2 * f;
        }
      }
      if (ok)
        l = mid;
      else
        r = mid - 1;
    }
    cout << l << "\n";
  }
}

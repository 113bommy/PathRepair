#include <bits/stdc++.h>
using namespace std;
ifstream in;
ofstream out;
const long long kk = 1000;
const long long ml = kk * kk;
const long long mod = ml * kk + 7;
const long long inf = ml * ml * ml + 7;
long long n, i, j, s, ans;
vector<long long> t1, t2;
vector<long long> m, was, ones;
bool viv = false;
void build() {
  s = 1;
  while (s < n) s <<= 1;
  t1.resize(2 * s);
  t2.resize(2 * s);
  for (long long i = 0; i < n; i++) t1[s + i] = m[i];
  for (long long i = s - 1; i > 0; i--) t1[i] = max(t1[2 * i], t1[2 * i + 1]);
  vector<long long> las(n, -1);
  for (long long i = 0; i < n; i++) {
    long long val = m[i];
    was.push_back(las[val]);
    las[val] = i;
  }
  for (long long i = 0; i < n; i++) t2[s + i] = was[i];
  for (long long i = n; i < s; i++) t2[s + i] = -1;
  for (long long i = s - 1; i > 0; i--) t2[i] = max(t2[2 * i], t2[2 * i + 1]);
}
long long maxi(long long l, long long r, long long v, long long tl,
               long long tr) {
  if (r < tl || tr < l) return 0;
  if (l <= tl && tr <= r) return t1[v];
  long long tm = tl + tr >> 1;
  long long v1 = maxi(l, r, 2 * v, tl, tm);
  long long v2 = maxi(l, r, 2 * v + 1, tm + 1, tr);
  return max(v1, v2);
}
long long rep(long long l, long long r, long long v, long long tl,
              long long tr) {
  if (r < tl || tr < l) return -1;
  if (l <= tl && tr <= r) return t2[v];
  long long tm = tl + tr >> 1;
  long long v1 = rep(l, r, 2 * v, tl, tm);
  long long v2 = rep(l, r, 2 * v + 1, tm + 1, tr);
  return max(v1, v2);
}
void work() {
  ones.push_back(-1);
  for (long long i = 0; i < n; i++)
    if (m[i] == 1) ones.push_back(i);
  ones.push_back(n);
  if (viv) {
    for (auto i : ones) cout << i << ' ';
    cout << endl;
  }
  for (long long i = 1; i < ones.size() - 1; i++) {
    long long pl = ones[i];
    if (viv) cout << "Work1 " << pl << endl;
    long long lans = 1;
    long long ma = 1;
    for (long long j = pl + 1; j < ones[i + 1]; j++) {
      ma = max(ma, m[j]);
      long long l = j - ma + 1;
      if (viv)
        cout << "Will check " << l << ' ' << j << endl,
            cout << maxi(l, j, 1, 0, s - 1) << ' ' << rep(l, j, 1, 0, s - 1)
                 << endl;
      if (l >= 0 && maxi(l, j, 1, 0, s - 1) == ma && rep(l, j, 1, 0, s - 1) < l)
        lans++;
    }
    if (viv) cout << lans << endl << endl;
    ans += lans;
  }
  for (long long i = 1; i < ones.size() - 1; i++) {
    long long pl = ones[i];
    if (viv) cout << "Work2 " << pl << endl;
    long long lans = 0;
    long long ma = 1;
    for (long long j = pl - 1; j > ones[i - 1]; j--) {
      ma = max(ma, m[j]);
      long long r = j + ma - 1;
      if (r <= n - 1 && maxi(j, r, 1, 0, s - 1) == ma &&
          rep(j, r, 1, 0, s - 1) < j)
        lans++;
    }
    if (viv) cout << lans << endl << endl;
    ans += lans;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (i = 0; i < n; i++) {
    long long a;
    cin >> a;
    m.push_back(a);
  }
  build();
  work();
  cout << ans << endl;
  return 0;
}

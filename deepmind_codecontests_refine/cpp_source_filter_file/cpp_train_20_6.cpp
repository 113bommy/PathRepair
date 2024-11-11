#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int M = 2e3 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);
template <class T>
inline void read(T &x) {
  char c;
  x = 1;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') x = -1;
  T res = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
  x *= res;
}
int n, m;
char str[N];
int f[N][2];
int lowbit(int x) { return x & (-x); }
long long get(int pos, int type) {
  long long res = 0;
  while (pos) {
    res += f[pos][type];
    pos -= lowbit(pos);
  }
  return res;
}
void update(int pos, int v) {
  while (pos <= m) {
    f[pos][0]++;
    f[pos][1] += v;
    pos += lowbit(pos);
  }
}
void solve() {
  read(n);
  vector<pair<int, int> > p(n);
  for (pair<int, int> &pp : p) read(pp.first);
  for (pair<int, int> &pp : p) read(pp.second);
  sort(p.begin(), p.end());
  vector<int> v;
  for (pair<int, int> &pp : p) v.push_back(pp.second);
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  m = v.size();
  long long ans = 0;
  for (pair<int, int> &pp : p) {
    int pos = lower_bound(v.begin(), v.end(), pp.second) - v.begin();
    long long cnt = get(pos + 1, 0), sum = get(pos + 1, 1);
    ans += cnt * pp.first - sum;
    update(pos + 1, pp.first);
  }
  cout << ans << endl;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

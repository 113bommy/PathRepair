#include <bits/stdc++.h>
using namespace std;
template <class T>
using vc = vector<T>;
template <class T>
using vvc = vc<vc<T>>;
template <class T>
void mkuni(vector<T>& v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}
long long rand_int(long long l, long long r) {
  static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
  return uniform_int_distribution<long long>(l, r)(gen);
}
template <class T>
void print(T x, int suc = 1) {
  cout << x;
  if (suc == 1)
    cout << '\n';
  else
    cout << ' ';
}
template <class T>
void print(const vector<T>& v, int suc = 1) {
  for (int i = 0; i < v.size(); i++)
    print(v[i], i == (int)(v.size()) - 1 ? suc : 2);
}
const int INF = 0x3f3f3f;
const int maxn = 2e5 + 7;
const int mod = 1e9 + 7;
int a[maxn];
int n, k;
int t;
int nxt[maxn][26];
int sum[maxn];
int c[maxn];
int lowbit(int x) { return x & (-x); }
void updata(long long x, long long val) {
  if (x == 0) return;
  while (x <= n) {
    c[x] += val;
    x += lowbit(x);
  }
}
int getsum(int x) {
  long long res = 0;
  while (x) {
    res += c[x];
    x -= lowbit(x);
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<int> pos[26];
  string s;
  cin >> s;
  for (int i = n - 1; i >= 0; --i) pos[s[i] - 'a'].push_back(i);
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    bool fl = 0;
    char tar = s[n - i - 1];
    int p = pos[tar - 'a'].back();
    pos[tar - 'a'].pop_back();
    int pnow = p + getsum(p + 1);
    ans += pnow - (i);
    if (pnow != i) updata(1, 1), updata(p + 1, -1);
    ;
  }
  cout << ans << endl;
  return 0;
}

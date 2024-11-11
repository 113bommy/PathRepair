#include <bits/stdc++.h>
using namespace std;
string v2s(vector<long long int>& A) {
  long long int Z = ((long long int)A.size());
  string second(Z, ' ');
  for (long long i = 0; i < Z; i++) second[i] = A[i] + '0';
  return second;
}
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 5;
const long long int INF = 1e18;
const double PI = acos(-1.0);
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}
void prnt(vector<long long int> v) {
  long long int n = v.size();
  for (long long int i = 0; i < n; i++) cout << v[i] << " \n"[i == n - 1];
}
long long int powMod(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % MOD;
    x = (x * x) % MOD;
    y >>= 1;
  }
  return res;
}
long long int stringdigitsum(string digits) {
  long long int num, total = 0;
  for (int i = 0; i < digits.length(); i++) {
    num = digits.at(i) - '0';
    assert(0 <= num && num <= 9);
    total += num;
  }
  return total;
}
vector<pair<long long int, long long int> > A;
bool cmp(pair<long long int, long long int>& a,
         pair<long long int, long long int>& b) {
  return a.second < b.second;
}
void sortMP(map<long long int, long long int>& M) {
  for (auto& it : M) {
    A.push_back(it);
  }
  sort(A.begin(), A.end(), cmp);
}
char ar[110][110];
long long int vis[110][110];
bool ok = false;
long long int n, m;
void dfs(long long int x, long long int y, long long int fx, long long int fy,
         char c) {
  if (x < 0 || x >= n || y < 0 || y >= m) return;
  if (ar[x][y] != c) return;
  if (vis[x][y]) {
    ok = true;
    return;
  }
  vis[x][y] = 1;
  for (long long i = 0; i < 4; i++) {
    long long int nx = x + dx[i];
    long long int ny = y + dy[i];
    if (nx == fx && ny == fy) continue;
    dfs(nx, ny, x, y, c);
  }
}
int main() {
  long long int a, b, i, c, d, e, g, r, j,
      k = 0, l, f = 0, h = 0, tttt = 0, o = 0, q, t = 0, x, p, u, w, z, y, cnt;
  string s, s1, s2, s3;
  char cc, ccc, cccc;
  memset(vis, 0, sizeof(vis));
  cin >> a >> b;
  n = a;
  m = b;
  for (long long i = 0; i < a; i++)
    for (long long j = 0; j < b; j++) cin >> ar[i][j];
  for (long long i = 0; i < a; i++)
    for (long long j = 0; j < b; j++) {
      if (!vis[i][j]) {
        dfs(i, j, -1, -1, ar[i][j]);
      }
    }
  if (ok)
    printf("Yes\n");
  else
    printf("No\n");
}

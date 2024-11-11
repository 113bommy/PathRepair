#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
const string task = "";
template <class T>
T sqr(T x) {
  return x * x;
}
const int nmax = 100100;
int used[nmax];
vector<int> g[10];
int n, m;
string s[nmax];
int pr[nmax][10];
int res[nmax];
string mat[6];
int CUR;
int st[nmax][6];
vector<pair<string, int> > what[6];
void go(int pos) {
  if (pos == m - 1) {
    CUR++;
    return;
  }
  int now = 0;
  for (int j = 0; j < (int)(pos); j++) now = now * 10 + mat[pos][j] - '0';
  for (int i = st[now][pos]; i < n; i++) {
    if (pr[i][pos] > now) break;
    if (pos == m - 1) {
      CUR++;
      continue;
    }
    for (int j = pos; j < s[i].size(); j++) mat[pos][j] = mat[j][pos] = s[i][j];
    go(pos + 1);
  }
}
int solve(string s) {
  for (int i = 0; i < (int)(s.size()); i++) mat[i] = s;
  for (int i = 0; i < (int)(s.size()); i++) mat[0][i] = mat[i][0] = s[i];
  CUR = 0;
  go(1);
  return CUR;
}
void add(int a) {
  int len = 0, v = a;
  while (v > 0) {
    len++;
    v /= 10;
  }
  for (int i = len; i <= 5; i++) g[i].push_back(a);
}
void pre_calc(int len) {
  sort(g[len].begin(), g[len].end());
  n = g[len].size();
  m = len;
  for (int i = 0; i < (int)(n); i++) {
    int now = g[len][i];
    s[i] = "";
    for (int j = 0; j < (int)(len); j++) s[i] += "0";
    for (int j = (int)(len)-1; j >= 0; j--) {
      s[i][j] = now % 10 + '0';
      now /= 10;
    }
    for (int j = 0; j < (int)(len + 1); j++)
      pr[i][j] = atoi(s[i].substr(0, j).data());
  }
  s[n] = "999999";
  s[n][0]++;
  for (int j = 0; j <= 5; j++) {
    int now = 0;
    for (int i = 0; i < nmax; i++) {
      while (pr[now][j] < i) now++;
      st[i][j] = now;
    }
  }
  for (int i = 0; i < (int)(what[len].size()); i++) {
    res[what[len][i].second] = solve(what[len][i].first);
  }
}
int main() {
  memset(used, 0, sizeof used);
  used[0] = used[1] = 1;
  for (int i = 2; i < nmax; i++)
    if (!used[i]) {
      add(i);
      for (int j = 2 * i; j < nmax; j += i) used[j] = 1;
    }
  int tst;
  cin >> tst;
  for (int i = 0; i < (int)(tst); i++) {
    string s;
    cin >> s;
    what[s.size()].push_back(make_pair(s, i));
  }
  memset(res, 255, sizeof res);
  for (int i = 1; i <= 5; i++) {
    if (g[i].size() == 0) continue;
    pre_calc(i);
  }
  for (int i = 0; i < (int)(tst); i++) cout << res[i] << endl;
  cerr << clock() << endl;
  return 0;
  for (int i = 0; i < (int)(30); i++)
    cout << g[5][1500 + rand() % (g[5].size() - 1500)] << endl;
  cerr << clock() << endl;
  return 0;
}

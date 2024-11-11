#include <bits/stdc++.h>
using namespace std;
struct _ {
  _() { ios_base::sync_with_stdio(0); }
} _;
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> t) {
  o << "(" << t.first << ", " << t.second << ")";
  return o;
}
template <class T>
string tostring(T first, int len = 0, char c = '0') {
  stringstream ss;
  ss << first;
  string r = ss.str();
  if (r.length() < len) r = string(len - r.length(), c) + r;
  return r;
}
template <class T>
void PV(T a, T b, int n = 0, int w = 0, string s = " ") {
  int c = 0;
  while (a != b) {
    cout << tostring(*a++, w, ' ');
    if (a != b && (n == 0 || ++c % n))
      cout << s;
    else
      cout << endl;
  }
}
template <class T>
inline bool chmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
}
template <class T>
inline bool chmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
}
const long long linf = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = int(1e9) + 7;
const int N = 5005;
int n, m;
vector<string> s;
vector<vector<int>> L, R, U, D;
vector<vector<int>> L1, R1, U1, D1;
int main() {
  cin >> n >> m;
  s.resize(n);
  L.resize(n, vector<int>(m));
  R.resize(n, vector<int>(m));
  U.resize(n, vector<int>(m));
  D.resize(n, vector<int>(m));
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    {
      int pre = -1;
      for (int j = 0; j < m; j++) {
        L[i][j] = pre;
        if (s[i][j] != '.') pre = j;
      }
    }
    {
      int pre = -1;
      for (int j = m - 1; j >= 0; j--) {
        R[i][j] = pre;
        if (s[i][j] != '.') pre = j;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    {
      int pre = -1;
      for (int i = 0; i < n; i++) {
        U[i][j] = pre;
        if (s[i][j] != '.') pre = i;
      }
    }
    {
      int pre = -1;
      for (int i = n - 1; i >= 0; i--) {
        D[i][j] = pre;
        if (s[i][j] != '.') pre = i;
      }
    }
  }
  L1 = L;
  R1 = R;
  U1 = U;
  D1 = D;
  int res = 0;
  int num = 0;
  vector<string> ss = s;
  long long tot = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (ss[i][j] == '.') continue;
      long long t1 = clock();
      for (int first = 0; first < n; first++)
        for (int second = 0; second < m; second++) {
          L[first][second] = L1[first][second];
          R[first][second] = R1[first][second];
          U[first][second] = U1[first][second];
          D[first][second] = D1[first][second];
          s[first][second] = ss[first][second];
        }
      tot += clock() - t1;
      int ci = i, cj = j, ni = -1, nj = -1;
      int cnt = 0;
      while (1) {
        if (ci < 0 || cj < 0) break;
        char &ch = s[ci][cj];
        if (ch == '.') break;
        cnt++;
        if (ch == 'L')
          ni = ci, nj = L[ci][cj];
        else if (ch == 'R')
          ni = ci, nj = R[ci][cj];
        else if (ch == 'U')
          ni = U[ci][cj], nj = cj;
        else if (ch == 'D')
          ni = D[ci][cj], nj = cj;
        if (R[ci][cj] >= 0) L[ci][R[ci][cj]] = L[ci][cj];
        if (L[ci][cj] >= 0) R[ci][L[ci][cj]] = R[ci][cj];
        if (D[ci][cj] >= 0) U[D[ci][cj]][cj] = U[ci][cj];
        if (U[ci][cj] >= 0) D[U[ci][cj]][cj] = D[ci][cj];
        ch = '.';
        ci = ni, cj = nj;
      }
      if (res < cnt) {
        res = cnt;
        num = 1;
      } else if (res == cnt) {
        num++;
      }
    }
  cerr << "["
          "0"
          " -> "
          "tot"
          ": "
       << 1e3 * (tot - 0) / CLOCKS_PER_SEC << "ms]\n";
  ;
  cout << res << " " << num << endl;
  return 0;
}

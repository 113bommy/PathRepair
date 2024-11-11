#include <bits/stdc++.h>
using namespace std;
void readi(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readll(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = v * 10 + c - '0';
  while (isdigit(c = getchar())) v = v * 10 + c - '0';
  x = v * f;
}
void readc(char &x) {
  char c;
  while ((c = getchar()) == ' ')
    ;
  x = c;
}
void writes(string s) { puts(s.c_str()); }
void writeln() { writes(""); }
void writei(int x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
void writell(long long x) {
  if (!x) putchar('0');
  char a[25];
  int top = 0;
  while (x) {
    a[++top] = (x % 10) + '0';
    x /= 10;
  }
  while (top) {
    putchar(a[top]);
    top--;
  }
}
long long qp(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long z = qp(x, y / 2);
  z = z * z % 1000000007;
  if (y & 1) z = z * x % 1000000007;
  return z;
}
int n, m, i, j, fmp[524288], ffmp[524288], rt = 1, x, y, op, emp[524288], ecnt,
                                           hed[524288], ccnt;
vector<pair<int, int> > wyx[524288];
int M = 524288, Ta[524288 * 2 + 1];
int query(int s, int t) {
  int ans = 1;
  for (s = s + M - 1, t = t + M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
    if (~s & 1) ans &= Ta[s ^ 1];
    if (t & 1) ans &= Ta[t ^ 1];
  }
  return ans;
}
void update(int n, int v) {
  n += M;
  for (Ta[n] = v, n >>= 1; n; n >>= 1) Ta[n] = Ta[n + n] & Ta[n + n + 1];
}
void dfs(int x, int fa, int col, int hh) {
  int i;
  for (i = 0; i < wyx[x].size(); i++) {
    if (wyx[x][i].first == fa) continue;
    emp[wyx[x][i].second] = ++ecnt;
    ffmp[wyx[x][i].first] = emp[wyx[x][i].second];
    if (fa == 0) {
      hed[emp[wyx[x][i].second]] = emp[wyx[x][i].second];
      col = ++ccnt;
    } else
      hed[emp[wyx[x][i].second]] = hh;
    fmp[wyx[x][i].first] = col;
    dfs(wyx[x][i].first, x, col, hed[emp[wyx[x][i].second]]);
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> x >> y;
    wyx[x].push_back(make_pair(y, i));
    wyx[y].push_back(make_pair(x, i));
    update(i, 1);
  }
  for (i = 1; i <= n; i++)
    if (wyx[i].size() > 2) rt = i;
  dfs(rt, 0, 0, 0);
  cin >> m;
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> x;
      update(emp[x], 1);
    }
    if (op == 2) {
      cin >> x;
      update(emp[x], 0);
    }
    if (op == 3) {
      cin >> x >> y;
      if (x == y) {
        cout << "0\n";
        continue;
      }
      if (y == rt) swap(x, y);
      if (x == rt) {
        if (query(hed[ffmp[y]], ffmp[y])) {
          cout << ffmp[y] - hed[ffmp[y]] + 1 << endl;
        } else
          cout << -1 << endl;
      } else if (fmp[x] == fmp[y]) {
        if (query(min(ffmp[x], ffmp[y]), max(ffmp[x], ffmp[y]))) {
          cout << max(ffmp[x], ffmp[y]) - min(ffmp[x], ffmp[y]) << endl;
        } else
          cout << -1 << endl;
      } else {
        if (query(hed[ffmp[x]], ffmp[x]) && query(hed[ffmp[y]], ffmp[y])) {
          cout << ffmp[x] - hed[ffmp[x]] + ffmp[y] - hed[ffmp[y]] + 2 << endl;
        } else
          cout << -1 << endl;
      }
    }
  }
  return 0;
}

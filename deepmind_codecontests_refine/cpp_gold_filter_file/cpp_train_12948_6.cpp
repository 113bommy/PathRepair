#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-8;
template <class T>
inline void read(T &i) {
  bool minus = false;
  char c;
  for (c = getchar(); (c < '0' || c > '9') && (c != '-'); c = getchar())
    ;
  if (c == '-') {
    minus = true;
    c = '0';
  }
  for (i = 0; c >= '0' && c <= '9'; c = getchar())
    i = (i << 3) + (i << 1) + (c - 48);
  if (minus) i = (~i) + 1;
}
vector<string> parse(string s, string c) {
  int len = c.length(), p = -len, np;
  vector<string> ans;
  do {
    np = s.find(c, p + len);
    ans.push_back(s.substr(p + len, np - p - len));
    p = np;
  } while (p != string::npos);
  return ans;
}
long long f[100009], g[100009], w[100009];
vector<int> graf[100009];
void roosephu(int curr, int parent) {
  for (int i = 0; i < graf[curr].size(); i++) {
    int k = graf[curr][i];
    if (k == parent) continue;
    roosephu(k, curr);
    f[curr] = max(f[curr], f[k]);
    g[curr] = max(g[curr], g[k]);
  }
  int remain = w[curr] - f[curr] + g[curr];
  if (remain > 0)
    f[curr] += remain;
  else
    g[curr] -= remain;
}
int main() {
  int n, x, y;
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    graf[x].push_back(y);
    graf[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) cin >> w[i];
  roosephu(1, 0);
  cout << f[1] + g[1] << endl;
  return 0;
}

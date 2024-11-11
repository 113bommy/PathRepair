#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int infi = 1e9 + 7;
const long long infl = 1e18;
const long double eps = 1e-7;
const long double eps1 = 1e-10;
const int mod = (1e9 + 7);
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 9;
const int ver1 = (62 * 62);
vector<pair<int, int> > g[10000];
pair<int, int> st[10000];
vector<int> ans1;
void dfs(int v) {
  while (!g[v].empty()) {
    int to = -1;
    for (int i = 0; i < (int)g[v].size(); ++i) {
      int u = g[v][i].first;
      if (g[v][i].second != 1) {
        to = i;
        break;
      }
      if (to == -1 || st[u].second > st[g[v][to].first].second) {
        to = i;
      }
    }
    g[v][to].second--;
    int to1 = g[v][to].first;
    if (!g[v][to].second) {
      swap(g[v][to], g[v].back());
      g[v].pop_back();
    }
    dfs(to1);
  }
  ans1.push_back(v);
  return;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    char a, b, c;
    scanf("\n%c%c%c", &a, &b, &c);
    int q, w, e;
    if (a >= 'a' && a <= 'z') {
      q = a - 'a';
    } else {
      if (a >= 'A' && a <= 'Z') {
        q = a - 'A';
        q += 26;
      } else {
        q = a - '0';
        q += 52;
      }
    }
    if (b >= 'a' && b <= 'z') {
      w = b - 'a';
    } else {
      if (b >= 'A' && b <= 'Z') {
        w = b - 'A';
        w += 26;
      } else {
        w = b - '0';
        w += 52;
      }
    }
    if (c >= 'a' && c <= 'z') {
      e = c - 'a';
    } else {
      if (c >= 'A' && c <= 'Z') {
        e = c - 'A';
        e += 26;
      } else {
        e = c - '0';
        e += 52;
      }
    }
    int v = q * 62 + w;
    int to = w * 62 + e;
    int z = 0;
    for (int j = 0; j < (int)g[v].size(); ++j) {
      if (g[v][j].first == to) {
        ++g[v][j].second;
        z = 1;
      }
    }
    if (!z) {
      g[v].push_back(make_pair(to, 1));
    }
    ++st[to].first;
    ++st[v].second;
  }
  int v, u;
  v = u = -1;
  for (int i = 0; i < ver1; ++i) {
    if (st[i].first == st[i].second) {
      continue;
    }
    if (v == -1) {
      v = i;
    } else {
      if (u == -1) {
        u = i;
      } else {
        cout << "NO";
        return 0;
      }
    }
  }
  if (u != -1 || v != -1) {
    if (u == -1) {
      cout << "NO";
      return 0;
    }
    if (st[v].first != st[v].second - 1 || st[u].second != st[u].first - 1) {
      swap(u, v);
      if (st[v].first != st[v].second - 1 || st[u].second != st[u].first - 1) {
        cout << "NO";
        return 0;
      }
    }
  } else {
    for (int i = 0; i < ver1; ++i) {
      if (st[i].second) {
        v = i;
        break;
      }
    }
  }
  dfs(v);
  for (int i = 0; i < ver1; ++i) {
    if (!g[i].empty()) {
      cout << "NO";
      return 0;
    }
  }
  reverse(ans1.begin(), ans1.end());
  cout << "YES" << endl;
  for (int i = 0; i < (int)ans1.size(); ++i) {
    int q = ans1[i] / 62;
    int w = ans1[i] % 62;
    char a, b;
    if (q < 26) {
      a = 'a' + q;
    } else {
      q -= 26;
      if (q < 26) {
        a = 'A' + q;
      } else {
        q -= 26;
        a = '0' + q;
      }
    }
    if (w < 26) {
      b = 'a' + w;
    } else {
      w -= 26;
      if (w < 26) {
        b = 'A' + w;
      } else {
        w -= 26;
        b = '0' + w;
      }
    }
    if (!i) {
      printf("%c", a);
    }
    printf("%c", b);
  }
  return 0;
}

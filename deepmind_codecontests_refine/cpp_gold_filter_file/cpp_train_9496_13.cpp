#include <bits/stdc++.h>
using namespace std;
const int nsz = 1e2, msz = 1e5;
int n;
int es, hd[nsz + 5];
string tmp, ans, cs;
vector<string> s[nsz + 5];
struct edge {
  char a, b;
  int nxt, to;
  edge(){};
  edge(int nxt, int to, char a, char b) {
    this->nxt = nxt, this->to = to, this->a = a, this->b = b;
  }
};
edge e[msz + 5];
void inline link(int u, int v, char a, char b) {
  e[++es] = edge(hd[u], v, a, b), hd[u] = es;
  e[++es] = edge(hd[v], u, a, b), hd[v] = es;
}
void inline qry(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int len = r - l + 1, sum[26], cnt[26];
  string res[nsz + 5];
  for (int i = 1; i <= len; ++i) {
    s[i].clear();
  }
  for (int i = 1; i <= (len + 1) * len / 2; ++i) {
    string tmp;
    cin >> tmp;
    s[(int)tmp.size()].push_back(tmp);
  }
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i < s[1].size(); ++i) {
    ++sum[s[1][i][0] - 'a'];
  }
  for (int k = 2; k <= (len - 1) / 2 + 1; ++k) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s[k].size(); ++i) {
      for (int j = 0; j < s[k][i].size(); ++j) {
        ++cnt[s[k][i][j] - 'a'];
      }
    }
    for (int p = 2; p <= k - 1; ++p) {
      cnt[res[p][0] - 'a'] += k - p + 1;
      cnt[res[p][1] - 'a'] += k - p + 1;
    }
    for (int c = 0; c < 26; ++c) {
      int del = sum[c] * k - cnt[c];
      for (int d = 1; d <= del; ++d) {
        res[k] += c + 'a';
      }
    }
    link(l + k - 2, r - k + 2, res[k][0], res[k][1]);
  }
  if (len & 1) {
    memset(cnt, 0, sizeof(cnt));
    for (int k = 2; k <= len / 2 + 1; ++k) {
      ++cnt[res[k][0] - 'a'];
      ++cnt[res[k][1] - 'a'];
    }
    for (int c = 0; c < 26; ++c) {
      if (sum[c] - cnt[c]) {
        tmp[len / 2 + 1] = c + 'a';
        break;
      }
    }
  } else {
    memset(cnt, 0, sizeof(cnt));
    for (int k = 2; k <= len / 2; ++k) {
      ++cnt[res[k][0] - 'a'];
      ++cnt[res[k][1] - 'a'];
    }
    int cur = len / 2 + 1;
    for (int c = 0; c < 26; ++c) {
      int d = sum[c] - cnt[c];
      for (int i = 1; i <= d; ++i) {
        res[cur] += c + 'a';
      }
    }
    link(l + cur - 2, r - cur + 2, res[cur][0], res[cur][1]);
  }
  cs = res[2];
}
bool dfs(int u) {
  for (int i = hd[u]; i; i = e[i].nxt) {
    int v = e[i].to;
    char a = e[i].a, b = e[i].b, c = ans[u] == a ? b : a;
    if (ans[v] != ' ') {
      if (ans[v] != c) return 0;
      continue;
    }
    ans[v] = c;
    if (!dfs(v)) return 0;
  }
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  if (n == 1) {
    cout << "? " << 1 << ' ' << 1 << endl;
    string s;
    cin >> s;
    cout << "! " << s << endl;
    return 0;
  }
  tmp.resize(n + 1, ' ');
  qry(1, n);
  qry(1, n - 1);
  ans = tmp;
  if (ans[1] == ' ') {
    ans[1] = cs[0];
  }
  if (!dfs(1)) {
    ans = tmp;
    ans[1] = cs[1];
    dfs(1);
  }
  cout << "!" << ans << endl;
}

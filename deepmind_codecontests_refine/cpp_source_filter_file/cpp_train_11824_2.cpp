#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
const int maxn = 35, maxm = (int)1e5 + 10;
char s[maxn][maxm];
vector<pair<long long, long long> > hsh[maxn];
int len[maxn];
const int mod1 = (int)1e9 + 7, mod2 = (int)1e9 + 9;
pair<long long, long long> t[maxm];
pair<long long, long long> operator*(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  a.first *= b.first;
  a.second *= b.second;
  a.first %= mod1;
  a.second %= mod2;
  return a;
}
pair<long long, long long> operator+(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  a.first += b.first;
  a.second += b.second;
  if (a.first >= mod1) {
    a.first -= mod1;
  }
  if (a.second >= mod2) {
    a.second -= mod2;
  }
  return a;
}
pair<long long, long long> operator-(pair<long long, long long> a,
                                     pair<long long, long long> b) {
  a.first -= b.first;
  a.second -= b.second;
  if (a.first < 0) {
    a.first += mod1;
  }
  if (a.second < 0) {
    a.second += mod2;
  }
  return a;
}
pair<long long, long long> get_hsh(int it, int l, int r) {
  if (l == 0) {
    return hsh[it][r];
  } else {
    pair<long long, long long> f = hsh[it][r] - hsh[it][l - 1] * t[r - l + 1];
    return f;
  }
}
int sum[maxn];
vector<int> ed[maxm];
int used[maxm];
int dfs(int v) {
  used[v] = 1;
  for (int i = 0; i < (int)ed[v].size(); i++) {
    int u = ed[v][i];
    if (used[u] == 1 || (used[u] == 0 && dfs(u))) {
      return true;
    }
  }
  used[v] = 2;
  return false;
}
bool check(int l, int r) {
  for (int i = 0; i < maxn; i++) {
    ed[i].clear();
  }
  for (int i = l; i <= r; i++) {
    for (int j = l; j <= r; j++) {
      for (int pos = 0; pos < len[i]; pos++) {
        if (i == j && pos == 0) {
          continue;
        }
        if (len[j] > len[i] - pos) {
          if (get_hsh(i, pos, len[i] - 1) == get_hsh(j, 0, len[i] - pos - 1)) {
            ed[sum[i] + pos].push_back(sum[j] + len[i] - pos);
          }
        } else if (len[j] == len[i] - pos) {
          if (get_hsh(i, pos, len[i] - 1) == get_hsh(j, 0, len[i] - pos - 1) &&
              pos != 0) {
            for (int k = l; k <= r; k++) {
              ed[sum[i] + pos].push_back(sum[k]);
            }
          }
        } else {
          if (get_hsh(i, pos, pos + len[j] - 1) == get_hsh(j, 0, len[j] - 1)) {
            ed[sum[i] + pos].push_back(sum[i] + pos + len[j]);
          }
        }
      }
    }
  }
  memset(used, 0, sizeof used);
  for (int i = 0; i < maxm; i++) {
    if (used[i] == 0 && dfs(i)) {
      return false;
    }
  }
  return true;
}
int main() {
  t[0] = make_pair(1, 1);
  for (int i = 1; i < maxm; i++) {
    t[i] = t[i - 1] * make_pair(1234567, 1234567);
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
    pair<long long, long long> now = make_pair(0, 0);
    for (int j = 0; j < len[i]; j++) {
      now = now * t[1];
      now = now + make_pair((s[i][j] - 'a' + 1), s[i][j] - 'a' + 1);
      hsh[i].push_back(now);
    }
    if (i != 0) {
      sum[i] = sum[i - 1] + len[i - 1];
    }
  }
  int ans = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (r < i) {
      r = i;
    }
    while (r < n && check(i, r)) {
      r++;
    }
    ans += r - i;
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000100;
const int INF = 1e9 + 10;
int n, m, x;
char ch[60][60];
int q;
char s[maxn];
int ans[26];
bool has[26];
int dist(pair<int, int> A, pair<int, int> B) {
  int tx = A.first - B.first, ty = A.second - B.second;
  return tx * tx + ty * ty;
}
int get_ans(char c) {
  if (!has[c - 'A']) return 0;
  int res = n * n + m * m;
  vector<pair<int, int> > S, C;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (ch[i][j] == 'S')
        S.push_back(make_pair(i, j));
      else if (ch[i][j] - 'a' == c - 'A')
        C.push_back(make_pair(i, j));
    }
  }
  for (int i = 0; i < S.size(); i++) {
    for (int j = 0; j < C.size(); j++) {
      res = min(res, dist(S[i], C[j]));
    }
  }
  if (res <= x * x) return 0;
  return 1;
}
int main() {
  while (cin >> n >> m >> x) {
    memset(has, 0, sizeof(has));
    int S = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%s", ch[i] + 1);
      for (int j = 1; j <= m; j++) {
        if (ch[i][j] != 'S')
          has[ch[i][j] - 'a'] = 1;
        else
          S = 1;
      }
    }
    cin >> q;
    scanf("%s", s);
    if (!S) {
      int res = 0;
      for (int i = 0; i < q; i++) {
        if (isupper(s[i])) {
          res = -1;
          break;
        } else if (has[s[i] - 'a'] == 0) {
          res = -1;
          break;
        }
      }
      cout << res << endl;
      continue;
    }
    for (int i = 0; i < 26; i++) ans[i] = get_ans('A' + i);
    int res = 0;
    for (int i = 0; i < q; i++) {
      if (islower(s[i])) {
        if (!has[s[i] - 'a']) {
          res = -1;
          break;
        }
      } else {
        if (!has[s[i] - 'A']) {
          res = -1;
          break;
        } else
          res += ans[s[i] - 'A'];
      }
    }
    cout << res << endl;
  }
  return 0;
}

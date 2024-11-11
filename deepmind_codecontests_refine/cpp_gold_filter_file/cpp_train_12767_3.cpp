#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, string>;
using PP = pair<P, int>;
int n;
P ans[3][1 << 8];
bool v[3][1 << 8];
priority_queue<PP, vector<PP>, greater<PP> > pr;
int qiu(string s) {
  int ss = 0;
  for (int i = 0; i < 8; ++i) {
    if (s[i] == '1') ss |= 1 << i;
  }
  return ss;
}
int main() {
  scanf("%d", &n);
  int er = (1 << 8) - 1;
  pr.push(PP(P(1, "z"), qiu("01010101") << 2));
  pr.push(PP(P(1, "y"), qiu("00110011") << 2));
  pr.push(PP(P(1, "x"), qiu("00001111") << 2));
  while (!pr.empty()) {
    P a = pr.top().first;
    int id = pr.top().second >> 2;
    int qw = pr.top().second & 3;
    pr.pop();
    if (v[qw][id]) continue;
    v[qw][id] = 1;
    ans[qw][id] = a;
    if (qw == 0) {
      pr.push(PP(P(a.first + 1, "!" + a.second), (id ^ er) << 2));
      pr.push(PP(a, (id << 2) | 1));
      for (int i = (1 << 8) - 1; i >= 0; --i) {
        if (v[1][i]) {
          pr.push(PP(P(a.first + ans[1][i].first + 1,
                       ans[1][i].second + "&" + a.second),
                     ((id & i) << 2) | 1));
        }
      }
    } else if (qw == 1) {
      pr.push(PP(a, (id << 2) | 2));
      for (int i = (1 << 8) - 1; i >= 0; --i) {
        if (v[0][i]) {
          pr.push(PP(P(a.first + ans[0][i].first + 1,
                       a.second + "&" + ans[0][i].second),
                     ((id & i) << 2) | 1));
        }
        if (v[2][i]) {
          pr.push(PP(P(a.first + ans[2][i].first + 1,
                       ans[2][i].second + "|" + a.second),
                     ((id | i) << 2) | 2));
        }
      }
    } else {
      pr.push(PP(P(a.first + 2, "(" + a.second + ")"), id << 2));
      for (int i = (1 << 8) - 1; i >= 0; --i) {
        if (v[1][i]) {
          pr.push(PP(P(a.first + ans[1][i].first + 1,
                       a.second + "|" + ans[1][i].second),
                     ((id | i) << 2) | 2));
        }
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    char ww[10];
    scanf("%s", ww);
    int id = qiu(ww);
    cout << min(ans[0][id], min(ans[1][id], ans[2][id])).second << endl;
  }
  return 0;
}

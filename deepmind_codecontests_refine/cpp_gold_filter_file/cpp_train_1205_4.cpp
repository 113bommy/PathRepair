#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long linf = (long long)1e18;
template <typename Tp>
inline void read(Tp &res) {
  static char c;
  res = 0;
  static bool f;
  f = false;
  while (c = getchar(), c != '-' && (c < '0' || c > '9'))
    ;
  if (c == '-') f = true, c = getchar();
  do res = (res * 10) + (c ^ 48);
  while (c = getchar(), c >= '0' && c <= '9');
  if (f) res = -res;
}
template <typename Tp>
inline void print(Tp first) {
  static char stk[30];
  static int top;
  top = 0;
  if (first == 0) {
    putchar('0');
    return;
  }
  if (first < 0) {
    first = -first;
    putchar('-');
  }
  while (first) stk[++top] = first % 10 ^ 48, first /= 10;
  while (top) putchar(stk[top--]);
}
namespace Program {
const int N = 50;
int n, m;
char a[N + 5][N + 5], b[N + 5][N + 5];
bool rot;
void input() {
  scanf("%d %d", &n, &m);
  for (int i = 0, i_END_ = n; i < i_END_; ++i) scanf("%s", a[i]);
  for (int i = 0, i_END_ = n; i < i_END_; ++i) scanf("%s", b[i]);
  static char f[256];
  f['L'] = 'U';
  f['U'] = 'L';
  f['R'] = 'D';
  f['D'] = 'R';
  rot = false;
  if (n & 1) {
    rot = true;
    static char c[N + 5][N + 5];
    memcpy(c, a, sizeof a);
    for (int i = 0, i_END_ = n; i < i_END_; ++i)
      for (int j = 0, j_END_ = m; j < j_END_; ++j) a[j][i] = f[c[i][j]];
    memcpy(c, b, sizeof b);
    for (int i = 0, i_END_ = n; i < i_END_; ++i)
      for (int j = 0, j_END_ = m; j < j_END_; ++j) b[j][i] = f[c[i][j]];
    swap(n, m);
  }
}
vector<pair<int, int> > ans[2];
void ud(char w[N + 5][N + 5], vector<pair<int, int> > &vec, int first,
        int second);
void lr(char w[N + 5][N + 5], vector<pair<int, int> > &vec, int first,
        int second) {
  if (w[first][second] == 'L') return;
  ;
  ;
  ud(w, vec, first, second + 1);
  vec.push_back(pair<int, int>(first, second));
  w[first][second] = 'L';
  w[first][second + 1] = 'R';
  w[first + 1][second] = 'L';
  w[first + 1][second + 1] = 'R';
}
void ud(char w[N + 5][N + 5], vector<pair<int, int> > &vec, int first,
        int second) {
  if (w[first][second] == 'U') return;
  ;
  ;
  lr(w, vec, first + 1, second);
  vec.push_back(pair<int, int>(first, second));
  w[first][second] = 'U';
  w[first][second + 1] = 'U';
  w[first + 1][second] = 'D';
  w[first + 1][second + 1] = 'D';
}
void solve() {
  ;
  ;
  ans[0].clear();
  ans[1].clear();
  for (int i = 0; i < n; i += 2)
    for (int j = 0, j_END_ = m; j < j_END_; ++j) ud(a, ans[0], i, j);
  for (int i = 0; i < n; i += 2)
    for (int j = 0, j_END_ = m; j < j_END_; ++j) ud(b, ans[1], i, j);
  reverse(ans[1].begin(), ans[1].end());
}
void output() {
  printf("%d\n", (int)(ans[0]).size() + (int)(ans[1]).size());
  for (int i = 0, i_END_ = (int)(ans[0]).size(); i < i_END_; ++i) {
    if (!rot)
      printf("%d %d\n", ans[0][i].first + 1, ans[0][i].second + 1);
    else
      printf("%d %d\n", ans[0][i].second + 1, ans[0][i].first + 1);
  }
  for (int i = 0, i_END_ = (int)(ans[1]).size(); i < i_END_; ++i) {
    if (!rot)
      printf("%d %d\n", ans[1][i].first + 1, ans[1][i].second + 1);
    else
      printf("%d %d\n", ans[1][i].second + 1, ans[1][i].first + 1);
  }
}
void Main() {
  input();
  solve();
  output();
}
}  // namespace Program
int main() {
  Program::Main();
  return 0;
}

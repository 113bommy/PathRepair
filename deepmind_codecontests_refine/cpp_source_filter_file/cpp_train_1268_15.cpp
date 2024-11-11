#include <bits/stdc++.h>
using namespace std;
static const int maxn = 400005;
int n, p, M, m, gr_vis[maxn * 4] = {}, gr_col[maxn * 4] = {};
vector<int> gr_s[maxn * 4], gr_rs[maxn * 4], sa_ans;
stack<int> ko_ord;
struct Ircin_t {
  FILE *source;
  Ircin_t(FILE *_source = stdin) : source(_source) {}
  void figureIn(long long &dest) {
    long long sym = 1;
    dest = 0;
    char ch = 0;
    while (!isdigit(ch)) {
      if (ch == '-') sym = -1;
      ch = fgetc(source);
    }
    while (isdigit(ch)) {
      dest = dest * 10 + ch - '0';
      ch = fgetc(source);
    }
    dest *= sym;
  }
  Ircin_t &operator>>(long long &dest) {
    figureIn(dest);
    return *this;
  }
  Ircin_t &operator>>(int &dest) {
    long long temp;
    figureIn(temp);
    dest = static_cast<int>(temp);
    return *this;
  }
  template <typename _Left, typename _Right>
  Ircin_t &operator>>(pair<_Left, _Right> &dest) {
    return *this >> dest.first >> dest.second;
  }
} ircin;
void postdfs(int x) {
  gr_vis[x] = 1;
  int v;
  for (unsigned int i = 0; i < (gr_s[x]).size() && (v = (gr_s[x])[i], true);
       ++i) {
    if (!gr_vis[v]) postdfs(v);
  }
  ko_ord.push(x);
}
void paint(int x, int c) {
  gr_col[x] = c;
  int v;
  for (unsigned int i = 0; i < (gr_rs[x]).size() && (v = (gr_rs[x])[i], true);
       ++i) {
    if (!gr_col[v]) paint(v, c);
  }
}
inline void kosaraju() {
  int bruh = 0;
  for (int i = 1; i <= ((M + p) << 1); ++i)
    if (!gr_vis[i]) postdfs(i);
  while (!ko_ord.empty()) {
    if (!gr_col[ko_ord.top()]) paint(ko_ord.top(), ++bruh);
    ko_ord.pop();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int x, y;
  ircin >> n >> p >> M >> m;
  for (int i = 1; i <= (n); ++i) {
    ircin >> x >> y;
    gr_s[((x) << 1)].push_back((((y) << 1) - 1)),
        gr_rs[(((y) << 1) - 1)].push_back(((x) << 1));
    gr_s[((y) << 1)].push_back((((x) << 1) - 1)),
        gr_rs[(((x) << 1) - 1)].push_back(((y) << 1));
  }
  for (int i = 1; i <= (M - 1); ++i) {
    gr_s[((i + p + 1) << 1)].push_back(((i + p) << 1)),
        gr_rs[((i + p) << 1)].push_back(((i + p + 1) << 1));
    gr_s[(((i + p) << 1) - 1)].push_back((((i + p + 1) << 1) - 1)),
        gr_rs[(((i + p + 1) << 1) - 1)].push_back((((i + p) << 1) - 1));
  }
  for (int i = 1; i <= (p); ++i) {
    ircin >> x >> y;
    gr_s[(((i) << 1) - 1)].push_back((((y + p) << 1) - 1)),
        gr_rs[(((y + p) << 1) - 1)].push_back((((i) << 1) - 1));
    if (x - 1)
      gr_s[(((i) << 1) - 1)].push_back(((x - 1 + p) << 1)),
          gr_rs[((x - 1 + p) << 1)].push_back((((i) << 1) - 1));
    gr_s[((y + p) << 1)].push_back(((i) << 1)),
        gr_rs[((i) << 1)].push_back(((y + p) << 1));
    if (x - 1)
      gr_s[(((x - 1 + p) << 1) - 1)].push_back(((i) << 1)),
          gr_rs[((i) << 1)].push_back((((x - 1 + p) << 1) - 1));
  }
  for (int i = 1; i <= (m); ++i) {
    ircin >> x >> y;
    gr_s[(((x) << 1) - 1)].push_back(((y) << 1)),
        gr_rs[((y) << 1)].push_back((((x) << 1) - 1));
    gr_s[(((y) << 1) - 1)].push_back(((x) << 1)),
        gr_rs[((x) << 1)].push_back((((y) << 1) - 1));
  }
  kosaraju();
  for (int i = 1; i <= (M + p); ++i)
    if (gr_col[(((i) << 1) - 1)] == gr_col[((i) << 1)]) {
      putchar('-'), putchar('1');
      return 0;
    }
  for (int i = 1; i <= (p); ++i)
    if (gr_col[(((i) << 1) - 1)] > gr_col[((i) << 1)]) sa_ans.push_back(i);
  printf("%llu ", sa_ans.size());
  for (int i = 1; i <= (M); ++i)
    if (gr_col[(((i + p) << 1) - 1)] > gr_col[((i + p) << 1)])
      printf("%d\n", i), i = M + 1;
  for (unsigned int i = 0; i < (sa_ans).size() && (y = (sa_ans)[i], true); ++i)
    printf("%d ", y);
  return 0;
}

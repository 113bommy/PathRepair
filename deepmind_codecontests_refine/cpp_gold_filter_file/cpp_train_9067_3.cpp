#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
void _main();
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  _main();
}
const int inf = INT_MAX / 2;
const long long infl = 1LL << 60;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
int getrandmax() {
  static uint32_t y = time(NULL);
  y ^= (y << 13);
  y ^= (y >> 17);
  y ^= (y << 5);
  return abs((int)y);
}
int getrand(int l, int r) { return getrandmax() % (r - l + 1) + l; }
int N, K;
map<tuple<int, int, int>, int> memo;
int ask(int a, int b, int c) {
  if (a > c) swap(a, c);
  auto id = make_tuple(a, b, c);
  if (memo.count(id)) return memo[id];
  printf("? %d %d %d\n", a + 1, b + 1, c + 1);
  fflush(stdout);
  string s;
  cin >> s;
  if (s == "No") return memo[id] = 0;
  return memo[id] = 1;
}
void answer(int x) {
  printf("! %d\n", x + 1);
  fflush(stdout);
}
int getdpt() {
  int tot = 1, leave = 1, dpt = 0;
  while (tot < N) {
    leave *= K;
    tot += leave;
    dpt++;
  }
  return dpt;
}
int done[2010][2010];
void _main() {
  cin >> N >> K;
  int dpt = getdpt();
  for (int i = 0; i < N; i++) done[i][i] = 1;
  for (int _ = 0; _ < 1010; _++) {
    int a = getrand(0, N - 1);
    int c = getrand(0, N - 1);
    if (done[a][c]) continue;
    done[a][c] = done[c][a] = 1;
    vector<int> v;
    for (int i = 0; i < N; i++)
      if (i != a and i != c)
        if (ask(a, i, c)) v.push_back(i);
    if (v.size() == dpt * 2 + 1 - 2) {
      sort((v).begin(), (v).end(), [&](int x, int y) {
        if (ask(a, x, y)) return 1;
        return 0;
      });
      answer(v[dpt - 1]);
      return;
    }
  }
}

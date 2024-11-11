#include <bits/stdc++.h>
template <typename T>
inline void read(T &x) {
  char c;
  bool nega = 0;
  while ((!isdigit(c = getchar())) && (c != '-'))
    ;
  if (c == '-') {
    nega = 1;
    c = getchar();
  }
  x = c - 48;
  while (isdigit(c = getchar())) x = x * 10 + c - 48;
  if (nega) x = -x;
}
template <typename T>
inline void writep(T x) {
  if (x > 9) writep(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  writep(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
using namespace std;
int u, v, l, r;
vector<pair<int, int> > ans;
map<pair<int, int>, bool> dd;
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> u >> v;
  int up = 1, down = u;
  l = 1, r = v;
  while (up <= down) {
    if (l == 1) {
      for (int i = (1); i <= (v); ++i) {
        ans.push_back(make_pair(up, l));
        ++l;
        ans.push_back(make_pair(down, r));
        --r;
      }
      ++up;
      --down;
      --l;
      ++r;
    } else {
      for (int i = (1); i <= (v); ++i) {
        ans.push_back(make_pair(down, l));
        --l;
        ans.push_back(make_pair(down, r));
        ++r;
      }
      ++up;
      --down;
      ++l;
      --r;
    }
  }
  for (auto v : ans) {
    if (dd[v]) continue;
    dd[v] = 1;
    cout << v.first << ' ' << v.second << '\n';
  }
  return 0;
}

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
int n, m, q, t[2505][2505];
map<pair<pair<int, int>, pair<int, int> >, int> dd;
void Update(int x, int y, int val) {
  while (x <= n) {
    int temp = y;
    while (temp <= m) {
      t[x][temp] += val;
      if (t[x][temp] >= 1000000007) t[x][temp] -= 1000000007;
      temp += temp & -temp;
    }
    x += x & -x;
  }
}
void Add(int u, int v, int x, int y, int val) {
  Update(u, v, val);
  Update(x + 1, v, 1000000007 - val);
  Update(u, y + 1, 1000000007 - val);
  Update(x + 1, y + 1, val);
}
int Get(int x, int y) {
  int res = 0;
  while (x) {
    int temp = y;
    while (temp) {
      res += t[x][temp];
      if (res >= 1000000007) res -= 1000000007;
      temp -= temp & -temp;
    }
    x -= x & -x;
  }
  return res;
}
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> q;
  while (q--) {
    int type, x, y, u, v;
    cin >> type >> x >> y >> u >> v;
    if (type == 1) {
      int add = 1ll * rand() * rand() % 1000000007;
      dd[make_pair(make_pair(x, y), make_pair(u, v))] = add;
      Add(x, y, u, v, add);
    } else if (type == 2) {
      Add(x, y, u, v,
          1000000007 - dd[make_pair(make_pair(x, y), make_pair(u, v))]);
    } else {
      int ww = Get(x, y), qq = Get(u, v);
      cout << (ww == qq ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}

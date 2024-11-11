#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;
using vpii = vector<PII>;
using vi = vector<int>;
template <typename T>
istream& operator>>(istream& in, vector<T>& v) {
  for (auto& i : v) {
    in >> i;
  }
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T>& v) {
  for (auto& i : v) {
    out << i << " ";
  }
  out << endl;
  return out;
}
template <typename T, typename U>
void chkMin(T& a, U b) {
  if (a > b) {
    a = b;
  }
}
template <typename T, typename U>
void chkMax(T& a, U b) {
  if (a < b) {
    a = b;
  }
}
struct IO {
  char buf[(1 << 20)], *p1, *p2;
  char pbuf[(1 << 20)], *pp;
  IO() : p1(buf), p2(buf), pp(pbuf) {}
  ~IO() { fwrite(pbuf, 1, pp - pbuf, stdout); }
  inline char gc() {
    if (p1 == p2) {
      p2 = (p1 = buf) + fread(buf, 1, (1 << 20), stdin);
    }
    return p1 == p2 ? ' ' : *p1++;
  }
  inline bool blank(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
  }
  template <typename T>
  inline void read(T& x) {
    double tmp = 1;
    bool sign = 0;
    x = 0;
    char ch = gc();
    for (; !(ch >= '0' && ch <= '9'); ch = gc()) {
      if (ch == '-') {
        sign = 1;
      }
    }
    for (; (ch >= '0' && ch <= '9'); ch = gc()) {
      x = x * 10 + (ch - '0');
    }
    if (ch == '.') {
      for (ch = gc(); (ch >= '0' && ch <= '9'); ch = gc()) {
        tmp /= 10.0;
        x += tmp * (ch - '0');
      }
    }
    if (sign) {
      x = -x;
    }
  }
  inline void read(char* s) {
    char ch = gc();
    for (; blank(ch); ch = gc())
      ;
    for (; !blank(ch); ch = gc()) {
      *s++ = ch;
    }
    *s = 0;
  }
  inline void read(char& c) {
    for (c = gc(); blank(c); c = gc())
      ;
  }
  inline void push(const char& c) {
    if (pp - pbuf == (1 << 20)) {
      fwrite(pbuf, 1, (1 << 20), stdout);
      pp = pbuf;
    }
    *pp++ = c;
  }
  template <typename T>
  inline void write(T x) {
    if (x < 0) {
      x = -x;
      push('-');
    }
    static T sta[35];
    T top = 0;
    do {
      sta[top++] = x % 10;
      x /= 10;
    } while (x);
    while (top) {
      push(sta[--top] + '0');
    }
  }
  template <typename T>
  inline void write(T x, char lastChar) {
    write(x);
    push(lastChar);
  }
} io;
namespace Factor {
template <typename T>
inline T qpow(T a, T b, T m) {
  T c = 1;
  while (b) {
    if (b & 1) {
      c = c * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return c;
}
}  // namespace Factor
const int N = 1 << 20;
vpii g[N];
int part[N][2];
bool vis[N];
class Solution {
 public:
  Solution(int n) { this->n = n; }
  void solve() {
    for (int i = (int)(21) - 1; i >= 0; --i) {
      if (check((1 << i) - 1)) {
        cout << i << endl;
        restore((1 << i) - 1);
        break;
      }
    }
  }

 private:
  bool check(int mask) {
    for (int i = 0; i < (int)(mask + 1); ++i) {
      g[i].clear();
      vis[i] = false;
    }
    for (int i = 0; i < (int)(n); ++i) {
      int u = part[i][0] & mask;
      int v = part[i][1] & mask;
      g[u].push_back({v, 2 * i + 1});
      g[v].push_back({u, 2 * i + 2});
    }
    int comps = 0;
    for (int i = 0; i < (int)(mask + 1); ++i) {
      if ((int)(g[i]).size() & 1) {
        return false;
      }
      if (!vis[i] && (int)(g[i]).size() > 0) {
        ++comps;
        dfs(i);
      }
    }
    return comps == 1;
  }
  void dfs(int u) {
    vis[u] = true;
    for (auto& v : g[u]) {
      if (!vis[v.first]) {
        dfs(v.first);
      }
    }
  }
  void dfs2(int u, int prev = -1) {
    while ((int)(g[u]).size() > 0) {
      auto e = g[u].back();
      g[u].pop_back();
      if (vis[e.second / 2]) {
        continue;
      }
      vis[e.second / 2] = true;
      dfs2(e.first, e.second);
    }
    if (prev != -1) {
      ans.emplace_back(prev);
      ans.emplace_back(prev ^ 1);
    }
  }
  void restore(int mask) {
    for (int i = 0; i < (int)(n); ++i) {
      vis[i] = false;
    }
    for (int i = 0; i < (int)(mask + 1); ++i) {
      if ((int)(g[i]).size()) {
        dfs2(i);
      }
    }
    for (int i = 0; i < (int)(2 * n); ++i) {
      cout << ans[i] + 1 << " \n"[i + 1 == 2 * n];
    }
  }

 private:
  int n;
  vi ans;
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) {
    cin >> part[i][0] >> part[i][1];
  }
  Solution solution(n);
  solution.solve();
}

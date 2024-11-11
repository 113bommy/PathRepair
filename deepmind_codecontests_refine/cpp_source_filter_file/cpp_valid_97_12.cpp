#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e6 + 5;
const long long maxm = 1e3 + 5;
namespace IO {
const int SIZE = (1 << 20) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = obuf + SIZE - 1;
char _st[55];
int _qr = 0;
inline char gc() {
  return (iS == iT ? iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
          (iS == iT ? EOF : *iS++) : *iS++);
}
inline void qread() {}
template <class T1, class... T2>
inline void qread(T1 &IEE, T2 &...ls) {
  register T1 __ = 0, ___ = 1;
  register char ch;
  while (!isdigit(ch = gc())) ___ = (ch == '-') ? -___ : ___;
  do {
    __ = (__ << 1) + (__ << 3) + (ch ^ 48);
  } while (isdigit(ch = gc()));
  __ *= ___;
  IEE = __;
  qread(ls...);
  return;
}
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
  return;
}
inline void putc_(char _x) {
  *oS++ = _x;
  if (oS == oT) flush();
}
inline void qwrite() {}
template <class T1, class... T2>
inline void qwrite(T1 IEE, T2... ls) {
  if (!IEE) putc_('0');
  if (IEE < 0) putc_('-'), IEE = -IEE;
  while (IEE) _st[++_qr] = IEE % 10 + '0', IEE /= 10;
  while (_qr) putc_(_st[_qr--]);
  qwrite(ls...);
  return;
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher;
}  // namespace IO
using namespace IO;
long long n, m;
char s[505][505];
long long head[maxn], nex[maxn << 1];
long long to[maxn << 1];
long long cur;
void add(long long u, long long v) {
  nex[++cur] = head[u];
  to[cur] = v;
  head[u] = cur;
  return;
}
const long long dar[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
long long f[505][505];
long long id(long long x, long long y) { return (x - 1) * m + y; }
long long col[maxn];
queue<long long> q;
void bfs(long long now) {
  q.push(now);
  col[now] = 0;
  while (!q.empty()) {
    long long fr = q.front();
    q.pop();
    for (int i = head[fr]; i; i = nex[i]) {
      long long t = to[i];
      if (col[t] > -1 && col[t] != col[fr] ^ 1) {
        cout << "NO\n";
        cout.flush();
        exit(0);
      }
      if (col[t] > -1) continue;
      col[t] = col[fr] ^ 1;
      q.push(t);
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> (s[i] + 1);
  }
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      if (s[i][j] == '.') continue;
      long long cnt = 0;
      for (int k = 0; k < 4; k++) {
        long long tx = i + dar[k][0];
        long long ty = j + dar[k][1];
        if (s[tx][ty] == '.') cnt++;
      }
      if (cnt & 1) {
        cout << "NO\n";
        cout.flush();
        return 0;
      }
      if (cnt == 0) {
        f[i][j] = 0;
        continue;
      } else if (cnt == 2) {
        f[i][j] = 5;
        for (int k = 0; k < 4; k++) {
          long long nx = (k + 1) % 4;
          long long tx = i + dar[k][0];
          long long ty = j + dar[k][1];
          if (s[tx][ty] == s[i + dar[nx][0]][j + dar[nx][1]] &&
              s[tx][ty] == '.') {
            add(id(tx, ty), id(i + dar[nx][0], j + dar[nx][1]));
            add(id(i + dar[nx][0], j + dar[nx][1]), id(tx, ty));
            break;
          }
        }
        for (int k = 0; k < 4; k++) {
          long long nx = (k + 2) % 4;
          long long tx = i + dar[k][0];
          long long ty = j + dar[k][1];
          if (s[tx][ty] == s[i + dar[nx][0]][j + dar[nx][1]] &&
              s[tx][ty] == '.') {
            add(id(tx, ty), id(i + dar[nx][0], j + dar[nx][1]));
            add(id(i + dar[nx][0], j + dar[nx][1]), id(tx, ty));
            break;
          }
        }
      } else if (cnt == 4) {
        f[i][j] = 10;
        add(id(i - 1, j), id(i, j - 1));
        add(id(i, j - 1), id(i - 1, j));
        add(id(i + 1, j), id(i, j + 1));
        add(id(i, j + 1), id(i + 1, j));
      }
    }
  }
  memset(col, -1, sizeof(col));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (s[i][j] == '.' && col[id(i, j)] == -1) {
        bfs(id(i, j));
      }
      if (s[i][j] == '.') {
        f[i][j] = col[id(i, j)] == 1 ? 1 : 4;
      }
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << f[i][j] << " ";
    }
    cout << "\n";
  }
  cout.flush();
  return 0;
}

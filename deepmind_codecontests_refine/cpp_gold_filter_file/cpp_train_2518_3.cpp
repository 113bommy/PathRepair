#include <bits/stdc++.h>
using namespace std;
template <typename T>
void chkmax(T &x, T y) {
  x = x > y ? x : y;
}
template <typename T>
void chkmin(T &x, T y) {
  x = x > y ? y : x;
}
template <typename T>
void update(T &x, T y, T mod) {
  x = x + y > mod ? x + y - mod : x + y;
}
const int INF = (1ll << 30);
template <typename T>
void read(T &x) {
  x = 0;
  bool f = 1;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = 0;
  } while (ch > '9' || ch < '0');
  do {
    x = x * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  x = f ? x : -x;
}
template <typename T>
void write(T x) {
  if (x < 0) x = ~x + 1, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
int T, n, a0, a1, b0, b1, a01, b10, mark;
string a, b;
vector<int> sol;
inline void clear() {
  a0 = a1 = b0 = b1 = a01 = b10 = 0;
  mark = -1;
  sol.clear();
}
inline void solve() {
  clear();
  cin >> a >> b;
  n = a.length();
  for (int i = 0; i < n; i += 2) {
    if (a[i] == '0' && a[i + 1] == '0') a0++;
    if (a[i] == '1' && a[i + 1] == '1') a1++;
    if (b[i] == '0' && b[i + 1] == '0') b0++;
    if (b[i] == '1' && b[i + 1] == '1') b1++;
  }
  if (a0 != b0 || a1 != b1) {
    puts("-1");
    return;
  }
  for (int i = 0; i < n; i += 2) {
    if (a[i] == '0' && a[i + 1] == '1') a01++;
    if (b[i] == '1' && b[i + 1] == '0') b10++;
  }
  if (a01 != b10) {
    int delta = 0;
    for (int i = 0; i < n; i += 2) {
      if (a[i] == '1' && a[i + 1] == '0') delta--;
      if (a[i] == '0' && a[i + 1] == '1') delta++;
      if (a01 - delta == b10) {
        sol.push_back(i + 2);
        reverse(a.begin(), a.begin() + i + 2);
        break;
      }
    }
    if (!sol.size()) {
      delta = 0;
      for (int i = 0; i < n; i += 2) {
        if (b[i] == '1' && b[i + 1] == '0') delta++;
        if (b[i] == '0' && b[i + 1] == '1') delta--;
        if (b10 - delta == a01) {
          mark = i + 2;
          reverse(b.begin(), b.begin() + i + 2);
          break;
        }
      }
    }
  }
  for (int i = 0; i < n; i += 2) {
    for (int j = i; j < n; j += 2) {
      if (b[n - i - 1] == a[j] && b[n - i - 2] == a[j + 1]) {
        if (j) sol.push_back(j);
        reverse(a.begin(), a.begin() + j);
        sol.push_back(j + 2);
        reverse(a.begin(), a.begin() + j + 2);
        break;
      }
    }
  }
  if (mark != -1) sol.push_back(mark);
  printf("%d\n", (int)sol.size());
  for (int i = 0; i < (int)sol.size(); i++)
    printf("%d%c", sol[i], i == sol.size() - 1 ? '\n' : ' ');
}
int main() {
  read(T);
  while (T--) solve();
  return 0;
}

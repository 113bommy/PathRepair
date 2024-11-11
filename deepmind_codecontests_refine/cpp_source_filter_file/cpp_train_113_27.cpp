#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pdd = pair<ld, ld>;
int __intend = 0;
void nextIntend() { __intend++; }
void prevIntend() { __intend--; }
string getIntend() {
  string r;
  for (int i = 0; i < __intend; ++i) {
    r += '\t';
  }
  return r;
}
template <typename T>
void print(const char s[], bool intend, T& v) {
  if (intend) cout << getIntend();
  cout << s << " = " << v << endl;
}
template <typename T, typename... TA>
void print(const char s[], bool intend, T& v, TA&... args) {
  if (intend) cout << getIntend();
  while (*s != ',') {
    if (*s != ' ') cout << *s;
    s++;
  }
  while (*s == ',' || *s == ' ') s++;
  cout << " = " << v << " | ";
  print(s, false, args...);
}
int query(int c, int d) {
  cout << "? " << c << ' ' << d << endl;
  cout.flush();
  int ans;
  cin >> ans;
  return ans;
}
void answer(int a, int b) {
  cout << "! " << a << ' ' << b << endl;
  cout.flush();
}
int a, b;
void solve() {
  int a = 0;
  int b = 0;
  int st = query(a, b);
  for (int bit = 1 << 30; bit > 0; bit >>= 1) {
    int q1, q2;
    switch (st) {
      case 0:
        q1 = query(a | bit, b);
        if (q1 < 0) {
          a |= bit;
          b |= bit;
        }
        break;
      case 1:
        q1 = query(a | bit, b);
        if (q1 <= 0) {
          a |= bit;
          st = q1;
        }
        if (!q1) break;
        q2 = query(a, b | bit);
        if (q1 <= 0 && q2 <= 0) {
          st = q1;
        }
        if (q1 < 0 && q2 > 0) {
          b |= bit;
          st = q2;
        }
        if (q1 > 0 && q2 < 0) {
          st = 1;
        }
        if (q1 > 0 && q2 >= 0) {
          a |= bit;
          st = 1;
        }
        break;
      case -1:
        q1 = -query(a, b | bit);
        if (q1 <= 0) {
          b |= bit;
          st = -q1;
        }
        if (!q1) break;
        q2 = -query(a | bit, b);
        if (q1 <= 0 && q2 < 0) {
          st = -q1;
        }
        if (q1 <= 0 && q2 > 0) {
          a |= bit;
          st = -q2;
        }
        if (q1 > 0 && q2 < 0) {
          st = -1;
        }
        if (q1 > 0 && q2 >= 0) {
          b |= bit;
          st = -1;
        }
    }
  }
  answer(a, b);
}
int squery(int c, int d) {
  if ((a ^ c) == (b ^ d)) return 0;
  if ((a ^ c) > (b ^ d))
    return 1;
  else
    return -1;
}
pii ssolve() {
  int a = 0;
  int b = 0;
  int st = squery(a, b);
  for (int bit = 1 << 30; bit > 0; bit >>= 1) {
    int q1, q2;
    switch (st) {
      case 0:
        q1 = squery(a | bit, b);
        if (q1 < 0) {
          a |= bit;
          b |= bit;
        }
        break;
      case 1:
        q1 = squery(a | bit, b);
        if (q1 <= 0) {
          a |= bit;
          st = q1;
        }
        if (!q1) break;
        q2 = squery(a, b | bit);
        if (q1 <= 0 && q2 <= 0) {
          st = q1;
        }
        if (q1 < 0 && q2 > 0) {
          b |= bit;
          st = q2;
        }
        if (q1 > 0 && q2 < 0) {
          st = 1;
        }
        if (q1 > 0 && q2 >= 0) {
          a |= bit;
          st = 1;
        }
        break;
      case -1:
        q1 = -squery(a, b | bit);
        if (q1 <= 0) {
          b |= bit;
          st = -q1;
        }
        if (!q1) break;
        q2 = -squery(a | bit, b);
        if (q1 <= 0 && q2 < 0) {
          st = -q1;
        }
        if (q1 <= 0 && q2 > 0) {
          a |= bit;
          st = -q2;
        }
        if (q1 > 0 && q2 < 0) {
          st = -1;
        }
        if (q1 > 0 && q2 >= 0) {
          b |= bit;
          st = -1;
        }
    }
  }
  return {a, b};
}
const bool fastIO = false;
const bool withTest = false;
const bool fileIO = false;
const bool stress = false;
int main() {
  srand(time(0));
  if (fileIO) {
    freopen(
        "file"
        ".in",
        "r", stdin);
    freopen(
        "file"
        ".out",
        "w", stdout);
  }
  if (fastIO) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
  }
  if (withTest) {
    int t;
    cin >> t;
    while (t--) solve();
  } else if (!stress)
    solve();
  else {
    while (true) {
      a = rand() % 1000;
      b = rand() % 1000;
      if (0)
        cout << "a"
             << " = " << a << " | "
             << "b"
             << " = " << b << " | " << endl;
      int ta, tb;
      tie(ta, tb) = ssolve();
      if (ta != a || tb != b) {
        cout << "ta"
             << " = " << ta << " | "
             << "tb"
             << " = " << tb << " | " << endl;
        cout << "error" << endl;
        break;
      }
    }
  }
}

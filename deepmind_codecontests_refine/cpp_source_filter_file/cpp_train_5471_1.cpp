#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
namespace input {
inline int nextInt() {
  int res = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
  return res;
}
inline long long nextLong() {
  long long res = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') res = res * 10 + c - '0', c = getchar();
  return res;
}
inline bool isSpace(const char &c) {
  return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
}
inline void next(char *str) {
  char c = getchar();
  while (isSpace(c)) c = getchar();
  size_t head = 0;
  while (!isSpace(c)) str[head++] = c, c = getchar();
  str[head] = 0;
}
inline char nextChar() {
  char c = getchar();
  while (isSpace(c)) c = getchar();
  return c;
}
}  // namespace input
using namespace input;
const int N = 2e6 + 5;
const int B = 4;
set<int> st;
unordered_map<int, int> cnt;
void solve() {
  int q = nextInt();
  cnt[0]++;
  st.insert(0);
  for (int i = 0; i < q; i++) {
    char op = nextChar();
    int x = nextInt();
    if (op == '+') {
      cnt[x]++;
      st.insert(x);
    } else if (op == '-') {
      cnt[x]--;
      if (cnt[x] == 0) {
        st.erase(x);
      }
    } else if (op == '?') {
      int mn = 0;
      for (int i = B - 1; i >= 0; i--) {
        if ((x & (1 << i)) == 0) {
          int y = mn | (1 << i);
          auto it = st.lower_bound(y);
          if (it != st.end()) {
            int low = *it;
            if ((low >> (i + 1)) == (mn >> (i + 1))) {
              mn = y;
            }
          }
        } else {
          int y = mn;
          auto it = st.lower_bound(y);
          if (it != st.end()) {
            int low = *it;
            if (low & (1 << i)) {
              mn |= 1 << i;
            }
          }
        }
      }
      printf("%d\n", mn ^ x);
    }
  }
}

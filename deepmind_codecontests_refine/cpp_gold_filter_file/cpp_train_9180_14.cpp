#include <bits/stdc++.h>
using namespace std;
template <typename tp>
inline void read(tp &x) {
  x = 0;
  register char c = getchar();
  register bool f = 0;
  for (; c < '0' || c > '9'; f |= (c == '-'), c = getchar())
    ;
  for (; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar())
    ;
  if (f) x = -x;
}
const int N = 3e5 + 5;
char s[N];
int d[N], n, up[N], down[N], mid[N], remain[N];
pair<int, int> Up[N];
int main() {
  read(n);
  scanf("%s", s + 1);
  int maxn = 0;
  for (int i = 1; i <= n; ++i) {
    if (s[i] == ')')
      d[i] = d[i - 1] + 1;
    else
      d[i] = d[i - 1] - 1;
    maxn = max(maxn, d[i]);
  }
  if (d[n] != 0) {
    puts("0\n1 1");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    up[i] = up[i - 1] + (d[i] == maxn);
    mid[i] = mid[i - 1] + (d[i] == maxn - 1);
  }
  int ans = up[n], pls = 1, PLS = 1;
  int l = 0x3f3f3f3f, r = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == maxn) {
      l = i;
      break;
    }
  }
  for (int i = n; i >= 1; --i) {
    if (d[i] == maxn) {
      r = i;
      break;
    }
  }
  if (ans < mid[n] - mid[r] + mid[l] && r < n) {
    ans = mid[n] - mid[r] + mid[l];
    PLS = r + 1;
    pls = l;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == maxn - 1) {
      l = i;
      break;
    }
  }
  for (int i = n; i >= 1; --i) {
    if (d[i] == maxn - 1) {
      r = i;
      break;
    }
  }
  for (int i = l; i <= r; ++i) {
    if (d[i] == maxn) cnt++;
  }
  for (int i = 1; i < l; ++i) {
    if (d[i] == maxn - 2) cnt++;
  }
  for (int i = r + 1; i <= n; ++i) {
    if (d[i] == maxn - 2) cnt++;
  }
  if (cnt > ans && r < n) {
    ans = cnt;
    PLS = l, pls = r + 1;
  }
  l = PLS, r = pls;
  int begin = 0, length = 0, Begin = 0, Length = 0;
  for (int i = 1; i <= n; ++i) {
    if (d[i] == maxn - 2) {
      if (begin == 0) {
        begin = i;
      }
      length++;
    }
    if (d[i] == maxn - 1) {
      if (begin) {
        if (ans < length + up[n]) {
          ans = length + up[n];
          r = i;
          l = begin;
        }
        begin = 0;
        length = 0;
      }
      if (Begin == 0) {
        Begin = i;
      }
      Length++;
    }
    if (d[i] == maxn) {
      if (Begin) {
        if (ans < Length) {
          ans = Length;
          r = i;
          l = Begin;
        }
        Begin = Length = 0;
      }
    }
  }
  printf("%d\n", ans);
  printf("%d %d\n", l, r);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, N = 5e5 + 10, P1 = 1e9 + 7, P2 = 1e9 + 9, B1 = 23,
          B2 = 233;
template <class T>
inline int chkmin(T &first, const T &second) {
  return second < first ? first = second, 1 : 0;
}
template <class T>
inline int chkmax(T &first, const T &second) {
  return first < second ? first = second, 1 : 0;
}
long long pw1[N], pw2[N];
struct Hash {
  long long a, b;
  int len;
  bool operator==(const Hash &B) const { return a == B.a && b == B.b; }
  void Add(int first) {
    a = (a * B1 + first) % P1;
    b = (b * B2 + first) % P2;
    ++len;
  }
  void Addh(int first) {
    a = (a + pw1[len] * first) % P1;
    b = (b + pw2[len] * first) % P2;
    ++len;
  }
} sum[N], sumh[N];
int n, m, cnt[2], c[2];
char s[N], t[N];
int main() {
  pw1[0] = pw2[0] = 1;
  for (int i = (0), i_end = (N - 1); i <= i_end; ++i) {
    pw1[i] = pw1[i - 1] * B1 % P1;
    pw2[i] = pw2[i - 1] * B2 % P2;
  }
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  for (int i = (1), i_end = (n); i <= i_end; ++i) cnt[s[i] - '0']++;
  for (int i = (1), i_end = (m); i <= i_end; ++i) {
    sum[i] = sum[i - 1];
    sum[i].Add(t[i] - '0');
  }
  for (int i = (m), i_end = (1); i >= i_end; --i) {
    sumh[i] = sumh[i + 1];
    sumh[i].Addh(t[i] - '0');
  }
  int len = 0;
  for (int i = (m - 1), i_end = (1); i >= i_end; --i)
    if (sum[i] == sumh[m - i + 1]) {
      len = i;
      break;
    }
  for (int i = (1), i_end = (m); i <= i_end; ++i) cnt[t[i] - '0']--;
  if (cnt[0] < 0 || cnt[1] < 0) {
    printf("%s", s + 1);
  } else {
    printf("%s", t + 1);
    while (1) {
      int las0 = cnt[0], las1 = cnt[1];
      for (int i = (len + 1), i_end = (m); i <= i_end; ++i) cnt[t[i] - '0']--;
      if (cnt[0] < 0 || cnt[1] < 0) {
        for (int i = (1), i_end = (las0); i <= i_end; ++i) putchar('0');
        for (int i = (1), i_end = (las1); i <= i_end; ++i) putchar('1');
        break;
      }
      for (int i = (len + 1), i_end = (m); i <= i_end; ++i) putchar(t[i]);
    }
  }
  return 0;
}

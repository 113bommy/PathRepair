#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = (x << 1) + (x << 3) + c - '0', c = getchar();
  return x * f;
}
char s[N];
int s1[N], s0[N];
int main() {
  int T = read();
  while (T--) {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
      s1[i] = s1[i - 1] + (s[i] == '1');
      s0[i] = s0[i - 1] + (s[i] == '0');
      cnt1 += (s[i] == '1');
      cnt0 += (s[i] == '0');
    }
    int mi = min(cnt0, cnt1);
    for (int i = 1; i <= n; i++) {
      mi = min(mi, min(s1[i], s0[i]) + min(n - s1[i], n - s0[i]));
    }
    cout << mi << endl;
  }
}

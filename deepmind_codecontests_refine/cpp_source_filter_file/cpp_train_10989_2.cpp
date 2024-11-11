#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
long long cnt[80];
long long n;
int ans;
int main() {
  cnt[0] = 1;
  cnt[1] = 2;
  for (int i = 2; i <= 70; i++) cnt[i] = cnt[i - 1] + cnt[i - 2] + 1;
  while (cin >> n) {
    ans = 0;
    for (int i = 1; i <= 70; i++) {
      if (cnt[i] >= n) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}

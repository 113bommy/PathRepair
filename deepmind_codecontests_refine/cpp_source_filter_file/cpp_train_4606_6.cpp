#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
const int M = 1e5 + 2;
const int mod = 998244353;
const int inf = 1e9;
const long long INF = 1e16;
void data() {}
int x, p[6] = {1, 6, 4, 5, 3}, num[6];
int main() {
  data();
  scanf("%d", &x);
  for (int i = 6; i >= 1; --i) {
    int bit = (x & (1 << (i - 1)));
    if (i == 6) {
      num[6] = (bit != 0);
    }
    if (i == 5) {
      num[3] = (bit != 0);
    }
    if (i == 4) {
      num[1] = (bit != 0);
    }
    if (i == 3) {
      num[4] = (bit != 0);
    }
    if (i == 2) {
      num[2] = (bit != 0);
    }
    if (i == 1) {
      num[5] = (bit != 0);
    }
  }
  int ans = 0;
  int pw = 1;
  for (int i = 1; i <= 6; ++i) {
    ans += num[i] * pw;
    pw *= 2;
  }
  printf("%d", ans);
}

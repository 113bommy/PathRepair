#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long _INF = 0xc0c0c0c0c0c0c0c0;
const long long mod = (int)1e9 + 7;
const int N = 1e5 + 100;
vector<long long> vc[60];
long long ans[N], b[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &b[i]);
    for (int j = 59; j >= 0; --j)
      if ((b[i] >> j) & 1) {
        vc[j].push_back(b[i]);
        break;
      }
  }
  long long cur = 0;
  for (int i = 1; i <= n; ++i) {
    int f = 0;
    for (int j = 0; j < 60; ++j) {
      if (vc[j].size() && !(cur & (1 << j))) {
        ans[i] = vc[j].back();
        vc[j].pop_back();
        cur ^= ans[i];
        f = 1;
        break;
      }
    }
    if (!f) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; ++i) {
    printf("%lld%c", ans[i], " \n"[i == n]);
  }
  return 0;
}

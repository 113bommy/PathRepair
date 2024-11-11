#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
int boy[maxn], girl[maxn];
int n, m;
int main() {
  int b, g;
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(boy, 0, sizeof(boy));
    memset(girl, 0, sizeof(girl));
    int in;
    scanf("%d", &b);
    for (int i = 0; i < b; i++) {
      scanf("%d", &in);
      boy[in] = 1;
    }
    scanf("%d", &g);
    for (int i = 0; i < g; i++) {
      scanf("%d", &in);
      girl[in] = 1;
    }
    bool flag;
    int stb = 0, stg = 0;
    int cnt = maxn * maxn;
    while (cnt) {
      flag = true;
      stb %= n;
      stg %= m;
      if (boy[stb] || girl[stg]) {
        boy[stb] = 1;
        girl[stg] = 1;
      }
      for (int i = 0; i < n; i++) {
        if (!boy[i]) {
          flag = false;
          break;
        }
      }
      for (int i = 0; i < m; i++) {
        if (!girl[i]) {
          flag = false;
          break;
        }
      }
      if (flag) break;
      stb++;
      stg++;
      cnt--;
    }
    printf("%s\n", flag ? "Yes" : "No");
  }
  return 0;
}

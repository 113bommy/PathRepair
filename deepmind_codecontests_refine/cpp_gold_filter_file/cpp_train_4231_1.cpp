#include <bits/stdc++.h>
using namespace std;
static const int MAX_N = 2e5 + 5;
static const long long Mod = 233;
static const int N = 105;
static const int INF = 0x3f3f3f3f;
int ar[MAX_N];
bool jg[MAX_N];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &ar[i]);
      jg[i] = false;
    }
    int rev = 0;
    for (int i = n; i >= 1; --i) {
      if (jg[i]) continue;
      jg[i] = true;
      int p = i;
      ++rev;
      while (ar[p] != 0 || !jg[ar[p]]) {
        jg[ar[p]] = true;
        p = ar[p];
      }
    }
    printf("%d\n", rev);
  }
  return 0;
}

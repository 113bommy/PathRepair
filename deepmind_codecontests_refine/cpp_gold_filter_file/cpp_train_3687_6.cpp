#include <bits/stdc++.h>
using namespace std;
const int maxn = 123456;
int ai[maxn];
int n, k;
void init() {
  for (int i = 1; i <= n; i++) scanf("%d", &ai[i]);
}
void play() {
  for (int i = k + 1; i <= n; i++) {
    ai[i] += ai[i - k];
  }
  int MIN = 1000000000;
  int idx = -1;
  for (int i = n; i >= n - k + 1; i--) {
    if (ai[i] <= MIN) {
      MIN = ai[i];
      idx = i % k;
      if (idx == 0) idx = k;
    }
  }
  printf("%d\n", idx);
}
int main() {
  while (scanf("%d%d", &n, &k) != EOF) {
    init();
    play();
  }
  return 0;
}

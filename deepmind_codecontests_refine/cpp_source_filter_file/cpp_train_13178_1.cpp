#include <bits/stdc++.h>
using namespace std;
void run();
int main() {
  ios::sync_with_stdio(0);
  run();
}
int deg[10000002];
int man[10000002];
char wd[10000002];
char buf[5000002];
void run() {
  int n;
  scanf(" %s%n", buf, &n);
  for (int i = 0, j = 0; i < n; ++i, j += 2) {
    wd[j] = buf[i];
  }
  int done = 0;
  int piv = man[0] = 0;
  for (int i = 1; i < n * 2 - 1; ++i) {
    if (piv + man[piv] >= i) {
      man[i] = min(man[piv * 2 - i], piv + man[piv] - i);
    }
    while (i - man[i] > 0 and i + man[i] < n * 2 - 2 and
           wd[i - man[i] - 1] == wd[i + man[i] + 1])
      ++man[i];
    if (piv + man[piv] < i + man[i]) piv = i;
  }
  long long res = deg[0] = 1;
  for (int i = 1; i < n; ++i) {
    if (man[i] == i) {
      res += (deg[i] = deg[(i & ~2) / 2] + 1);
    }
  }
  cout << res << endl;
}

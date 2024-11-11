#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int n;
int s[maxn];
int main() {
  int i, j;
  while (scanf("%d", &n) != EOF) {
    memset(s, 0, sizeof(s));
    for (i = 0; i < n; i++) {
      scanf("%d", &s[i]);
    }
    int sum = 0;
    int sum1 = 0;
    for (i = 0; i < n; i++) {
      if (s[i] == -1) {
        if (sum1 == 0)
          ++sum;
        else
          --sum1;
      } else
        sum1 += s[i];
    }
    cout << sum << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int size = 200000;
char s[size + 10], t[size + 10];
long long pre[30];
int main() {
  int len;
  while (~scanf("%d", &len)) {
    scanf("%s %s", (s + 1), (t + 1));
    double total = 0;
    double res = 0;
    for (int i = 1; i <= len; ++i) {
      total += 1.0 * i * i;
    }
    for (int i = 1; i <= len; ++i) {
      if (s[i] == t[i]) {
        res += 1.0 * i * (len - i + 1);
      }
    }
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= len; ++i) {
      res += 1.0 * pre[s[i] - 'A'] * (len - i + 1);
      pre[t[i] - 'A'] += i;
    }
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= len; ++i) {
      res += 1.0 * pre[t[i] - 'A'] * (len - i + 1);
      pre[s[i] - 'A'] += i;
    }
    printf("%.10lf\n", res * 1.0 / total);
  }
  return 0;
}

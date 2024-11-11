#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
char str[MAXN];
set<int> se;
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    scanf("%s", str);
    se.clear();
    int dot = 0;
    for (int i = 0; i < n; i++) {
      if (str[i] == '.') {
        dot = i + 1;
        break;
      }
    }
    for (int i = dot; i < n; i++) {
      if (str[i] > '4') {
        se.insert(i);
        break;
      }
    }
    int now = n;
    while (m--) {
      if (se.empty() || *se.begin() >= now) break;
      int tp = *se.begin();
      tp--;
      if (str[tp] == '.') {
        now = tp;
        str[tp - 1]++;
        break;
      }
      now = tp;
      str[now]++;
      if (str[now] > '4') se.insert(now);
      now++;
    }
    for (int i = dot - 2; i >= 0; i--) {
      if (i > 0)
        str[i - 1] += (str[i] - '0') / 10;
      else if (str[0] > '9')
        putchar('1');
      str[i] = (str[i] - '0') % 10 + '0';
    }
    for (int i = 0; i < now; i++) putchar(str[i]);
    puts("");
  }
  return 0;
}

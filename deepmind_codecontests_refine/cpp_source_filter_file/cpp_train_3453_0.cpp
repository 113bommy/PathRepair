#include <bits/stdc++.h>
using namespace std;
long long a[100005];
map<long long, int> qaq;
int main() {
  int n;
  cin >> n;
  long long tot = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%I64d", &a[i]);
    ++qaq[a[i]];
  }
  int qwq = 0, qqwq = -233;
  for (int i = 1; i <= n; ++i) {
    if (qaq[a[i]] == 3) {
      puts("cslnb");
      return 0;
    }
    if (qaq[a[i]] == 2 && (qaq[a[i] - 1] || a[i] == 0)) {
      puts("cslnb");
      return 0;
    }
    if (qaq[a[i]] == 2 && qwq && qqwq != a[i]) {
      puts("cslnb");
      return 0;
    }
    if (qaq[a[i]] == 2) {
      ++qwq;
      qqwq = a[i];
    }
  }
  sort(a + 1, a + 1 + n);
  long long ls = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] < ls) {
      continue;
    } else {
      tot += a[i] - ls;
      ++ls;
    }
  }
  if (tot & 1) {
    puts("sjfnb");
  } else {
    puts("cslnb");
  }
  return 0;
}

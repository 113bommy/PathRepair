#include <bits/stdc++.h>
using namespace std;
int n;
long long a[150002];
set<pair<long long, int>> s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    s.insert({a[i], i});
  }
  while (!s.empty()) {
    auto i = s.begin();
    i++;
    auto i2 = i;
    if (i == s.end()) break;
    i--;
    if ((*i).first == (*i2).first) {
      a[(*i).second] = 0;
      a[(*i2).second] = (*i2).first * 2;
      s.erase(*i);
      s.insert({(*i2).first * 2, (*i2).second});
      s.erase(*i2);
    } else
      s.erase(*i);
  }
  int c = 0;
  bool b = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) c++;
  }
  printf("%d\n", c);
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) {
      if (b) printf(" ");
      printf("%lld", a[i]);
      b = 1;
    }
  }
  puts("");
  return 0;
}

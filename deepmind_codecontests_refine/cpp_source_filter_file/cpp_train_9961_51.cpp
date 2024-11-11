#include <bits/stdc++.h>
using namespace std;
long long table[21];
int main() {
  long long n, i, ans;
  set<long long> s;
  s.insert(0);
  table[0] = 0;
  for (i = 1; i <= 20; i++) {
    set<long long> tmp;
    for (auto it : s) {
      tmp.insert(it + 1);
      tmp.insert(it + 5);
      tmp.insert(it + 10);
      tmp.insert(it + 50);
    }
    s = tmp;
    table[i] = s.size();
  }
  scanf("%I64d", &n);
  if (n <= 20)
    ans = table[n];
  else
    ans = table[20] + (n - 20) / 49;
  printf("%I64d\n", ans);
  return 0;
}

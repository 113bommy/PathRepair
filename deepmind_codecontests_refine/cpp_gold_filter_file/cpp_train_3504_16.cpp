#include <bits/stdc++.h>
using namespace std;
const int mxn = 1e5 + 5;
int n;
multiset<long long> s[66];
vector<long long> ans;
int high(long long x) {
  for (int(i) = (int)(60); (i) >= (int)(0); --(i))
    if (x & (1LL << i)) return i;
}
int main() {
  scanf("%d", &n);
  long long cur = 1LL << 60;
  for (int(i) = (int)(1); (i) <= (int)(n); ++(i)) {
    long long x;
    scanf("%lld", &x);
    s[high(x)].insert(x);
    cur = min(cur, x);
  }
  ans.push_back(cur);
  int tmp = high(cur);
  s[tmp].erase(s[tmp].begin());
  while (--n) {
    bool flag = 0;
    for (int(i) = (int)(0); (i) <= (int)(60); ++(i))
      if (~cur & (1LL << i)) {
        if (s[i].empty()) continue;
        long long v = *s[i].rbegin();
        ans.push_back(v);
        cur ^= v;
        s[i].erase(s[i].find(v));
        flag = 1;
        break;
      }
    if (!flag && n) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int(i) = (int)(0); (i) < (int)(ans.size()); ++(i))
    printf("%lld%c", ans[i], " \n"[i == ans.size() - 1]);
  return 0;
}

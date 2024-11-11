#include <bits/stdc++.h>
using namespace std;
int n, a[100005], S;
long long ret;
vector<int> p;
void solve(int x) {
  long long total = 0;
  int cur = 0;
  for (int i = (0); i < (n); i++)
    if (a[i] != 0) {
      cur += a[i];
      p.push_back(i);
      if (cur % x == 0) {
        cur = 0;
        int median = p[p.size() / 2];
        for (int j = (0); j < (p.size()); j++) total += abs(p[j] - median);
        p.clear();
      }
    }
  ret = min(ret, total);
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i < (n); i++) scanf("%d", &a[i]);
  for (int i = (0); i < (n); i++) S += a[i];
  if (S == 1) {
    puts("-1");
    return 0;
  }
  ret = (1 << 30);
  for (int i = 2; i <= S; i++)
    if (S % i == 0) solve(i);
  printf("%I64d\n", ret);
  return 0;
}

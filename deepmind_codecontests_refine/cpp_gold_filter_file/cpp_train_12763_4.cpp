#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long infLL = 0x3f3f3f3f3f3f3f3fLL;
const int maxn = 1000000 + 5;
int n;
int p[maxn];
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) scanf("%d", &p[i]);
  long long now = 0;
  multiset<int> grt;
  for (int i = (1); i <= (n); ++i) {
    if (p[i] > i)
      now += p[i] - i, grt.insert(p[i] - i);
    else
      now += i - p[i];
  }
  long long ret = now;
  int k = 0;
  for (int i = 1; i < n; ++i) {
    int j = n - i + 1;
    now -= n - p[j];
    now += p[j], grt.insert(p[j] + i - 1);
    now += n - (int)grt.size() * 2;
    while (!grt.empty() && *grt.begin() == i) grt.erase(grt.begin());
    if (now < ret) ret = now, k = i;
  }
  printf("%I64d %d\n", ret, k);
  return 0;
}

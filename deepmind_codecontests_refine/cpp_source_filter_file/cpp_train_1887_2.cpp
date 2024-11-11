#include <bits/stdc++.h>
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;
using namespace std;
int n;
int x;
map<int, int> mp;
int disc[N];
int cnt;
int res;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x);
    mp[x]++;
  }
  for (auto w : mp) {
    disc[++cnt] = w.second;
  }
  sort(disc + 1, disc + 1 + cnt);
  for (int i = 1; i <= n; ++i) {
    int sum = 0;
    int pos = 1;
    int now = i;
    while (true) {
      int tmp = lower_bound(disc + pos, disc + 1 + cnt, now) - disc;
      if (disc[tmp] == 0) break;
      sum += now;
      now *= 2;
      pos++;
    }
    res = max(res, sum);
  }
  printf("%d\n", res);
  return 0;
}

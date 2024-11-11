#include <bits/stdc++.h>
using namespace std;
map<int, long long> cnt;
int go(int x) {
  if (x == 0) return 0;
  return go(x / 2) + (x % 2);
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    cnt.clear();
    int x;
    for (int i = 0; i < (n); i++) {
      scanf("%d", &x);
      cnt[go(x)]++;
    }
    long long ans = 0;
    for (typeof(cnt.begin()) it = cnt.begin(); it != cnt.end(); it++)
      ans += it->second * (it->second - 1) / 2;
    cout << ans << endl;
  }
  return 0;
}

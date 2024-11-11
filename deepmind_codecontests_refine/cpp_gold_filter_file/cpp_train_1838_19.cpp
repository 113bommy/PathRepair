#include <bits/stdc++.h>
using namespace std;
long long p;
int k;
int cnt = 0;
int nums[105];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> p >> k;
  while (p != 0) {
    int x = p % k;
    if (x < 0) x += k;
    x %= k;
    nums[cnt] = x;
    cnt++;
    p -= x;
    p /= (-k);
  }
  cout << cnt << '\n';
  for (int i = 0; i < cnt; i++) cout << nums[i] << " ";
}

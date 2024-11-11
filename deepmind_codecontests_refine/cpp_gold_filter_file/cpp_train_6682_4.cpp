#include <bits/stdc++.h>
using namespace std;
long long lucky_num[1025];
long long sum(long long n) {
  if (n == 0) return 0;
  long long ans = 0;
  for (int i = 1; i <= 1024; i++) {
    if (lucky_num[i] < n)
      ans += lucky_num[i] * (lucky_num[i] - lucky_num[i - 1]);
    else {
      ans += lucky_num[i] * (n - lucky_num[i - 1]);
      break;
    }
  }
  return ans;
}
void solve() {
  long long l, r;
  cin >> l >> r;
  lucky_num[1] = 4;
  lucky_num[2] = 7;
  int t = 3;
  for (int i = 1; i < 512; i++) {
    lucky_num[t++] = lucky_num[i] * 10 + 4;
    lucky_num[t++] = lucky_num[i] * 10 + 7;
  }
  cout << sum(r) - sum(l - 1);
}
int main() {
  int test = 1;
  while (test--) solve();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, k;
  cin >> n >> k;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    long long int x1, x2, x3, x4;
    char ch1, ch2, ch3;
    cin >> x1 >> ch1 >> x2 >> ch2 >> x3 >> ch3 >> x4;
    x1 = x1 << 24;
    x2 = x2 << 16;
    x3 = x3 << 8;
    a[i] = x1 | x2 | x3 | x4;
  }
  long long int b[32];
  for (long long int i = 31; i >= 0; i--) b[31 - i] = (long long int)(-1) << i;
  set<long long int> data[32];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < 32; j++) {
      data[j].insert(a[i] & b[j]);
    }
  }
  long long int ans = -1;
  for (long long int i = 0; i < 32; i++)
    if (data[i].size() == k) {
      ans = i;
      break;
    }
  if (ans == -1)
    cout << "-1\n";
  else {
    long long int ans1, ans2, ans3, ans4;
    ans = ((-1 << (32 - (1 + ans))) & (((long long int)1 << 32) - 1));
    ans1 = ((1 << 8) - 1) & ans;
    ans = ans >> 8;
    ans2 = ((1 << 8) - 1) & ans;
    ans = ans >> 8;
    ans3 = ((1 << 8) - 1) & ans;
    ans = ans >> 8;
    ans4 = ((1 << 8) - 1) & ans;
    cout << ans4 << "." << ans3 << "." << ans2 << "." << ans1 << "\n";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
long long freq[25];
int main() {
  long long n, ans = 0, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    freq[x + 11]++;
  }
  ans += (freq[11] * (freq[11] - 1) / 2);
  for (int i = 12; i <= 21; i++) {
    ans += freq[i] * freq[11 - (i - 11)];
  }
  cout << ans;
  return 0;
}

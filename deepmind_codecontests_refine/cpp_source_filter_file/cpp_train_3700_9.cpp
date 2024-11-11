#include <bits/stdc++.h>
using namespace std;
long long n, arr[100010], sum = 0, ans = 100010;
map<long long, long long> mp;
int main() {
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    mp[sum]++;
    ans = min(ans, mp[sum]);
  }
  cout << ans << "\n";
}

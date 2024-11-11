#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n];
  unordered_map<long long, int> mp;
  unordered_map<long long, int> mp2;
  unordered_map<long long, int> mp3;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  for (int i = 0; i < n; i++) {
    for (long long j = 2; j < 1e9; j *= 2) {
      if (j - a[i] == a[i] && mp[a[i]] > 0) {
        mp2[j - a[i]]++;
      } else if (j - a[i] != a[i]) {
        mp3[j - a[i]]++;
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (mp2[a[i]] / mp[a[i]]) * (mp[a[i]] - 1);
    ans += mp3[a[i]];
  }
  cout << ans / 2 << endl;
  return 0;
}

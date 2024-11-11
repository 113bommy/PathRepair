#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  long long i, j;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  unordered_map<long long, long long> mp;
  i = 0, j = 0;
  long long cnt = 0;
  long long ans = n + 1;
  long long st = -1, end = -1;
  while (i < n && j < n) {
    if (mp[a[i]] == 0) cnt++;
    mp[a[i]]++;
    if (cnt == k && ans > i - j + 1) {
      ans = i - j + 1;
      st = j + 1;
      end = i + 1;
    }
    if (cnt >= k && j < i) {
      mp[a[j]]--;
      if (mp[a[j]] == 0) cnt--;
      j++;
      if (cnt == k && ans > i - j + 1) {
        ans = i - j + 1;
        st = j + 1;
        end = i + 1;
      }
    }
    i++;
  }
  cout << st << " " << end;
}

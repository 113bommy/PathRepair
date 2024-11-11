#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i) cin >> cnt[i];
  sort(cnt.begin(), cnt.end(), greater<int>());
  long long ans = 0;
  int prev = 1000000001;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] >= prev) cnt[i] = prev - 1;
    prev = cnt[i];
    ans += prev;
  }
  cout << ans << endl;
}

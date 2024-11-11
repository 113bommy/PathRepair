#include <bits/stdc++.h>
using namespace std;
long long bal, ans;
int main() {
  long long n, b;
  cin >> n >> b;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> cnt;
  for (int i = 0; i < n - 1; i++) {
    bal += -1 + (!(a[i] % 2) * 2);
    if (bal == 0) {
      cnt.push_back(abs(a[i] - a[i + 1]));
    }
  }
  sort(cnt.begin(), cnt.end());
  long long i = 0;
  while (i < cnt.size() && b > cnt[i]) {
    ans++;
    b -= cnt[i];
    i++;
  }
  cout << ans;
  return 0;
}

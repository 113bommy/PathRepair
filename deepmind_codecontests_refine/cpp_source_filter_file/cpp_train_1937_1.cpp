#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int cnt[3] = {};
  for (int i = 0; i < 3; i++) {
    for (int j = i; j < n; j++) {
      if (a[i] == a[j])
        cnt[i]++;
      else
        break;
    }
  }
  if (a[0] == a[1] && a[1] == a[2])
    cout << (cnt[0] * (cnt[0] - 1) * (cnt[0] - 2)) / 6;
  else if (a[0] == a[1])
    cout << (cnt[0] * (cnt[0] - 1) * cnt[2]) / 2;
  else if (a[1] == a[2])
    cout << (cnt[0] * cnt[1] * (cnt[1] - 1)) / 2;
  else
    cout << (cnt[1] * cnt[2] * cnt[0]);
  return 0;
}

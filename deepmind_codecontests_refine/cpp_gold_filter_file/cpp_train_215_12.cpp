#include <bits/stdc++.h>
using namespace std;
bool isV(char ch) {
  return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
void tc() {
  int n, m, x;
  cin >> n >> x;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  unsigned long long int ans = 0;
  if (v[n / 2] == x) {
    cout << 0;
    return;
  }
  if (v[n / 2] < x) {
    ans += 1LL * (x - v[n / 2]);
    v[n / 2] = x;
    for (int i = (n / 2) + 1; i < n; i++) {
      if (v[i] < v[i - 1]) {
        ans += 1LL * (v[i - 1] - v[i]);
        v[i] = v[i - 1];
      } else {
        break;
      }
    }
    cout << ans;
  } else if (v[n / 2] > x) {
    ans += 1LL * (v[n / 2] - x);
    v[n / 2] = x;
    for (int i = (n / 2) - 1; i >= 0; i--) {
      if (v[i] > v[i + 1]) {
        ans += 1LL * (v[i] - v[i + 1]);
        v[i] = v[i + 1];
      } else {
        break;
      }
    }
    cout << ans;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  tc();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s;
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  int med = v[n / 2];
  if (med == s) {
    cout << 0 << "\n";
    return 0;
  }
  long long ans1 = 0, ans2 = 0;
  for (int i = n / 2 + 1; i < n; i++) {
    if (v[i] < s) {
      ans1 += s - v[i];
    }
  }
  for (int i = 0; i < n / 2; i++) {
    if (v[i] > s) {
      ans1 += v[i] - s;
    }
  }
  ans1 += abs(s - v[n / 2]);
  cout << ans1 << "\n";
}

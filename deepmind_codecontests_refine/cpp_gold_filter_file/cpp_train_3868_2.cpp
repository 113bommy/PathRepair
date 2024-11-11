#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  std::vector<int> v;
  while (n != 0) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  if (v.size() == 1) {
    cout << v[0] << endl;
    return 0;
  } else if (v[0] == 1) {
    long long s = 1;
    for (int i = 0; i < v.size() - 1; i++) {
      s *= 9;
    }
    cout << s << endl;
    return 0;
  }
  long long ans = 1, ans1, mx;
  for (int i = 0; i < v.size(); i++) ans *= v[i];
  for (int i = 0; i < v.size(); i++) {
    long long p = 1, q = 1;
    for (int j = 0; j <= i - 1; j++) p *= v[j];
    for (int j = i + 1; j < v.size(); j++) q *= 9;
    mx = p * q * (v[i] - 1);
    if (ans < mx) ans = mx;
  }
  cout << ans << endl;
  return 0;
}

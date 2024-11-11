#include <bits/stdc++.h>
using namespace std;
long long dig2(long long n) { return log2(n) + 1; }
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<char> v;
  while (n--) {
    string s;
    cin >> s;
    v.push_back(s[0]);
  }
  sort(v.begin(), v.end());
  long long cnt = 1, ans = 0;
  for (int i = 0; i < v.size(); i++) {
    if (i > 0 && v[i] == v[i - 1]) cnt++;
    if (v[i] != v[i - 1] || i == v.size() - 1) {
      if (cnt == 1) continue;
      if (cnt % 2 != 0) ans += cnt / 2;
      cnt /= 2;
      ans += cnt * (cnt - 1);
      cnt = 1;
    }
  }
  cout << ans;
  return 0;
}

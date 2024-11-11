#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int ans = 0;
  int n, k;
  cin >> n >> k;
  map<int, int> m;
  for (int i = int(0); i < (int)n; ++i) {
    string s;
    cin >> s;
    m[s.size()]++;
  }
  string s;
  cin >> s;
  int target = s.size();
  int sum = 1;
  for (auto i : m) {
    if (i.first < target) {
      sum += i.second;
    }
  }
  ans += (sum) + ((sum - 1) / k) * 5;
  sum += m[target] - 1;
  int ans_max = sum + ((sum - 1) / k) * 5;
  cout << ans << " " << ans_max << endl;
  return 0;
}

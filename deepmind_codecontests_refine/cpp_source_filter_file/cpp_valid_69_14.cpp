#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void hehe() {
  for (int i = 0; i <= 40; i++) {
    long long a = pow(2, i);
    v.push_back(to_string(a));
  }
}
long long solve(string s) {
  int ans = 999999;
  int n = s.size();
  for (string &i : v) {
    int k = i.size();
    int cnt1 = 0, cnt2 = 0, count = 0;
    while (cnt1 < n && cnt2 < n) {
      if (s[cnt1] == i[cnt2]) {
        count++;
        cnt2++;
      }
      cnt1++;
    }
    ans = min(ans, n + k - 2 * count);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  ;
  hehe();
  int t, n;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << solve(s) << "\n";
  }
}

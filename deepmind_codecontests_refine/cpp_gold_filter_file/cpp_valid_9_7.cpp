#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int tests;
  cin >> tests;
  while (tests--) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto c : s) {
      ++mp[c];
    }
    vector<int> arr;
    arr.reserve(mp.size());
    for (auto [c, cnt] : mp) {
      arr.emplace_back(cnt);
    }
    sort(arr.rbegin(), arr.rend());
    int ans = 0;
    int cntOnes = 0;
    for (int i = 0; i < arr.size(); ++i) {
      if (arr[i] >= 2) {
        ++ans;
        arr[i] -= 2;
      } else if (arr[i] > 0) {
        ++cntOnes;
      }
    }
    ans += cntOnes / 2;
    cout << ans << '\n';
  }
}

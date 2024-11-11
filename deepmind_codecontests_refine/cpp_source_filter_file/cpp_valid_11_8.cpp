#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4.1")
#pragma GCC optimization("unroll-loops")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j;
  int tct;
  cin >> tct;
  while (tct--) {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    int ans = -1;
    for (i = 0; i < 6; i++) {
      vector<int> v;
      for (auto it : arr) {
        int cnt = 0;
        for (j = 0; j < it.length(); j++) {
          if (it[j] == 'a' + i) {
            cnt++;
          } else
            cnt--;
        }
        v.push_back(cnt);
      }
      sort(v.begin(), v.end(), greater<int>());
      if (v[0] < 0) continue;
      int ind = 0;
      int sum = 0;
      int cnt = 0;
      while (ind < n) {
        sum += v[ind];
        ind++;
        if (sum > 0) {
          cnt++;
        } else {
          break;
        }
      }
      ans = max(cnt, ans);
    }
    cout << ans << endl;
  }
  return 0;
}

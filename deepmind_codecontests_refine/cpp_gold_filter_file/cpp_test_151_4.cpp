#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    long long q;
    vector<vector<long long>> vec;
    vector<long long> actual(500007);
    for (long long i = 1; i <= 500005; i++) {
      actual[i] = i;
    }
    vector<long long> ans;
    cin >> q;
    long long n = q;
    while (q--) {
      long long x;
      cin >> x;
      if (x == 1) {
        long long y;
        cin >> y;
        vec.push_back({x, y});
      } else {
        long long y1, z1;
        cin >> y1 >> z1;
        vec.push_back({x, y1, z1});
      }
    }
    for (long long i = n - 1; i >= 0; i--) {
      if (vec[i][0] == 1) {
        ans.push_back(actual[vec[i][1]]);
      } else {
        actual[vec[i][1]] = actual[vec[i][2]];
      }
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << endl;
  }
}

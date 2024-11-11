#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
mt19937 gen;
int main() {
  iostream::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  const int PW = 60;
  long long cur = 0;
  vector<vector<long long>> ls(PW);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int l = -1;
    for (int j = 0; j < PW; j++) {
      if (a[i] & (1ll << j)) {
        l = j;
      }
    }
    ls[l].push_back(a[i]);
    cur ^= a[i];
  }
  vector<long long> ans;
  for (int i = 0; i < n; i++) {
    int whr = -1;
    for (int j = 0; j < PW; j++) {
      if (ls[j].size() && (cur & (1ll << j)) && whr == -1) {
        whr = j;
      }
    }
    if (whr == -1) {
      cout << "No\n";
      return 0;
    }
    ans.push_back(ls[whr].back());
    cur ^= ls[whr].back();
    ls[whr].pop_back();
  }
  cout << "Yes\n";
  reverse(ans.begin(), ans.end());
  for (long long x : ans) {
    cout << x << ' ';
  }
  return 0;
}

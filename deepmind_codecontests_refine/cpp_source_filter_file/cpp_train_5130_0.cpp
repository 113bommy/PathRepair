#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<string> data(n);
  for (int i = 0; i <= 29; i++) {
    long long tes = pow(2, i);
    for (int j = 0; j < n; j++) {
      if ((tes & a[j]) == tes) {
        data[j].push_back('1');
      } else {
        data[j].push_back('0');
      }
    }
  }
  vector<vector<int>> run(1);
  for (int i = 0; i < n; i++) {
    run[0].push_back(i);
  }
  long long b = 0;
  int ans = 0;
  vector<vector<int>> split;
  for (int i = 29; i >= 0; i--) {
    int sum1 = 0, sum0 = 0;
    for (vector<int> j : run) {
      vector<int> zero;
      vector<int> one;
      int cnt0 = 0, cnt1 = 0;
      for (int k : j) {
        if (data[k][i] == '1') {
          sum0 += cnt0;
          cnt1++;
          one.push_back(k);
        } else {
          sum1 += cnt1;
          cnt0++;
          zero.push_back(k);
        }
      }
      if (one.size() != 0) split.push_back(one);
      if (zero.size() != 0) split.push_back(zero);
    }
    if (sum1 > sum0) {
      ans += pow(2, i);
    }
    b += min(sum1, sum0);
    swap(split, run);
    split.clear();
  }
  cout << b << " " << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

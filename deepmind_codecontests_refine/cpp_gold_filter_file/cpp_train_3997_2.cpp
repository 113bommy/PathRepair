#include <bits/stdc++.h>
using namespace std;
int sum = 0;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<long long> nums;
  vector<pair<int, pair<int, int> > > ops;
  vector<long long> prefSumsOfRequests(m + 1, 0);
  vector<long long> prefSumsOfDeltaNums(n + 1, 0);
  for (int i = 0; i < n; i++) {
    long long num;
    cin >> num;
    nums.push_back(num);
  }
  for (int i = 0; i < m; i++) {
    int l, r, d;
    cin >> l >> r >> d;
    l--;
    r--;
    ops.push_back(make_pair(d, pair<int, int>(l, r)));
  }
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    prefSumsOfRequests[x]++;
    prefSumsOfRequests[y + 1]--;
  }
  for (int i = 1; i < m; i++) {
    prefSumsOfRequests[i] += prefSumsOfRequests[i - 1];
  }
  for (int i = 0; i < m; i++) {
    int l = ops[i].second.first, r = ops[i].second.second;
    long long d = ops[i].first * prefSumsOfRequests[i];
    prefSumsOfDeltaNums[l] += d;
    prefSumsOfDeltaNums[r + 1] -= d;
  }
  for (int i = 1; i < n; i++) {
    prefSumsOfDeltaNums[i] += prefSumsOfDeltaNums[i - 1];
  }
  for (int i = 0; i < n; i++) {
    nums[i] += prefSumsOfDeltaNums[i];
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}

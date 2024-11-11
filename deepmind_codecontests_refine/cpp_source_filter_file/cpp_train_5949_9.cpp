#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<pair<long long, int>> arr;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    arr.push_back(make_pair(x, (i + 1)));
  }
  sort(arr.begin(), arr.end(), greater<pair<long long, int>>());
  long long total = m * k;
  long long sum = 0;
  vector<int> pos;
  int p = 0;
  for (int i = 0; i < m * k; i++) {
    sum += arr[i].first;
    pos.push_back(arr[i].second);
  }
  cout << sum << endl;
  sort(pos.begin(), pos.end());
  for (int i = 0; i < (pos.size() - m); i += m) {
    if ((i + 1) % m == 0) cout << pos[i] << " ";
  }
}

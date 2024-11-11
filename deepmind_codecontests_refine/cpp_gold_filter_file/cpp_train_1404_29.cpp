#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
vector<int> indices;
int main() {
  int n, num, sumi(0), ans(0);
  long long k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> num;
    vec.push_back(make_pair(num, i + 1));
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < n; i++) {
    sumi += vec[i].first;
    if (sumi <= k) {
      ans++;
      indices.push_back(vec[i].second);
    } else
      break;
  }
  cout << ans << endl;
  for (int i = 0; i < ans; i++) {
    cout << indices[i] << " ";
  }
}

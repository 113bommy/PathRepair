#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, m;
  string s;
  cin >> n >> m;
  cin >> s;
  vector<long long int> vec;
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] == '0') vec.push_back(i);
  }
  m += 1;
  long long int indx = 0, ans = 1e18, sz = (long long int)vec.size(), diff;
  while (indx <= sz - m) {
    long long int left = indx, right = left + m - 1, mid, leftans, rightans,
                  last = right;
    while (left <= right) {
      mid = left + (right - left) / 2;
      leftans = vec[mid] - vec[indx];
      rightans = vec[last] - vec[mid];
      diff = max(leftans, rightans);
      ans = min(ans, diff);
      if (leftans == rightans) break;
      if (leftans > rightans)
        right = mid - 1;
      else
        left = mid + 1;
    }
    indx++;
  }
  cout << ans << endl;
}

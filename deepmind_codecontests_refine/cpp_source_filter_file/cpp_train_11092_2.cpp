#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> arr(n);
  string str;
  cin >> n >> str;
  for (auto i = 0; i < (n); ++i) {
    cin >> arr[i];
  }
  int MIN = INT_MAX;
  bool flag = false;
  for (auto i = 0; i < (n - 1); ++i) {
    if (str[i] == 'R' && str[i + 1] == 'L') {
      flag = true;
      MIN = min(MIN, (arr[i + 1] - arr[i]) / 2);
    }
  }
  if (!flag)
    cout << -1;
  else
    cout << MIN;
}

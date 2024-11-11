#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    vector<long long int> v = {3, 1, 4, 2};
    cin >> n;
    if (n <= 3)
      cout << "-1"
           << "\n";
    else if (n == 4)
      cout << "3 "
           << "1 "
           << "4 "
           << "2"
           << "\n";
    else {
      bool f = true;
      for (long long int i = 5; i <= n; i++) {
        v.push_back(i);
        reverse(v.begin(), v.end());
      }
      for (long long int i = 0; i < v.size(); i++) cout << v[i] << " ";
      cout << "\n";
    }
  }
  return 0;
}

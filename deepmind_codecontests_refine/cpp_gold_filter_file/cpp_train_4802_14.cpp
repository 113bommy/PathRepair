#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<long long> squares;
  for (long long i = 1; i * i <= 1e13; i++) {
    squares.push_back(i * i);
  }
  int n;
  cin >> n;
  vector<long long> a(n / 2);
  for (auto &x : a) cin >> x;
  long long sum = 0;
  vector<long long> ans;
  for (auto &x : a) {
    for (auto it = upper_bound(squares.begin(), squares.end(), sum);
         it != squares.end(); it++) {
      if (binary_search(squares.begin(), squares.end(), (*it) + x)) {
        ans.push_back(*it - sum);
        ans.push_back(x);
        sum = *it + x;
        break;
      }
      if (it + 1 == squares.end()) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  for (auto &x : ans) cout << x << " ";
  cout << endl;
}

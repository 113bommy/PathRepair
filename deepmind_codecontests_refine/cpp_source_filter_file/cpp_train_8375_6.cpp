#include <bits/stdc++.h>
using namespace std;
long long OR(long long i) { return i ^ (i + 1); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long cases;
  long long result;
  cin >> cases;
  long long left, right;
  while (cases--) {
    cin >> left >> right;
    while (left <= right) {
      result = left;
      left = OR(left);
    }
    cout << result << endl;
  }
}

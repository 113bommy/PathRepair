#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, j = 1, a, b, c = 0, sum = 0;
    ;
    cin >> n;
    long long int A[n];
    vector<long long int> v;
    for (i = 0; i < n; i++) {
      cin >> A[i];
      if (A[i] == 1) {
        v.push_back(i);
      }
    }
    for (auto it = v.begin(); it != v.end(); it++) {
      if (v.size() == 1) {
        sum = 0;
        break;
      }
      a = *it;
      it++;
      b = *it;
      c = b - a;
      if (v.size() == 2) {
        sum = c - 1;
        break;
      }
      if (b == 0) {
        break;
      }
      sum = sum + c - 1;
      it--;
    }
    cout << sum << endl;
  }
}

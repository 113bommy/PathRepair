#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long r, b, g;
    cin >> r >> b >> g;
    vector<long long> A;
    A.push_back(r);
    A.push_back(b);
    A.push_back(g);
    sort(A.begin(), A.end());
    long long m1 = A[2], m2 = A[1];
    if (m1 - m2 > 1)
      cout << "No\n";
    else
      cout << "Yes\n";
  }
}

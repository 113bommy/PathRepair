#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long lb = 1;
    long long rb = 2 * k;
    while (lb < rb) {
      long long mb = (lb + rb) / 2;
      if (mb - mb / n >= k) {
        rb = mb;
      } else {
        lb = mb + 1;
      }
    }
    cout << lb << endl;
  }
}

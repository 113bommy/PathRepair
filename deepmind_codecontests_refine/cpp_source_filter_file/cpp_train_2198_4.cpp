#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int q;
  cin >> q;
  for (long long int j = 0; j < q; j++) {
    long long int n;
    cin >> n;
    long long int ones = 0;
    while (n > 0) {
      long long int x = n & 1;
      ones = ones + x;
      n = n >> 1;
    }
    cout << pow(2, ones) << endl;
  }
}

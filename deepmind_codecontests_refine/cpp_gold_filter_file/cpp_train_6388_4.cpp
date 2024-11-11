#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int NUM = 100000;
int main() {
  int yu;
  cin >> yu;
  for (int test = 1; test <= yu; test++) {
    long long n;
    cin >> n;
    int ans = 0;
    if (n <= 2) {
      cout << 0 << "\n";
      continue;
    }
    cout << n - 2 << "\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  int s = 0;
  n -= k;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    s += t;
  }
  cout << s + k * x;
}

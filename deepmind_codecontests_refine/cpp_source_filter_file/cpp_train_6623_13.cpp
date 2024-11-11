#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x;
  cin >> n >> k >> x;
  int sum = k * x;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (i < n - 2) sum += a;
  }
  cout << sum << endl;
  return 0;
}

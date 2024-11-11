#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, x, ans = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    ans += (x + k - 1) / k;
  }
  cout << (ans + 1) / 2 << endl;
}

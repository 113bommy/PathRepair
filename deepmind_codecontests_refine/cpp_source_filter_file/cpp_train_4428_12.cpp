#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 0)
    cout << 1 << endl;
  else {
    long long k = n * (1 + n) / 2;
    cout << k * 6 + 1 << endl;
  }
  return 0;
}

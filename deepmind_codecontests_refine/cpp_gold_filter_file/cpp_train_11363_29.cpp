#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long int ans = 0;
  cin >> n;
  ans = ((n - 1) * n * (n + 1)) / 3 - 2;
  cout << ans << endl;
}

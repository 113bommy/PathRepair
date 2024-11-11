#include <bits/stdc++.h>
using namespace std;
int n, res;
int main() {
  cin >> n;
  int a;
  for (int i = 0; i < n; ++i) {
    cin >> a;
    res += a * i;
  }
  cout << res << endl;
  return 0;
}

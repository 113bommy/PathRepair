#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  if (n) {
    cout << 0;
    return 0;
  }
  cout << min(a, b) + min(min(a, b), c) * (n - 2);
}

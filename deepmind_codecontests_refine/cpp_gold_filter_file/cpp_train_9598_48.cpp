#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(b + 1, n - a);
  return 0;
}

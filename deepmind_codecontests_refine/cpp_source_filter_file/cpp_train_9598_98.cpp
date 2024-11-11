#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  cout << n - min(a + 1, n - b);
  return 0;
}

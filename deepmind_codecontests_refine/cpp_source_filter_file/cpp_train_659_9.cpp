#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int y, k, n;
  cin >> y >> k >> n;
  int notFound = 1;
  for (int i = 1; i <= n; i += k) {
    if (i - y > 0) {
      cout << i - y << " ";
      notFound = 0;
    }
  }
  if (notFound) cout << -1;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n == 1)
    cout << "1";
  else {
    if ((n - m) > (m - 1)) {
      cout << n - m;
    } else {
      cout << m - 1;
    }
  }
  return 0;
}

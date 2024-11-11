#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n != 1) {
    if (n - m >= m) {
      cout << m + 1;
    } else {
      cout << m - 1;
    }
  } else {
    cout << m;
  }
  return 0;
}

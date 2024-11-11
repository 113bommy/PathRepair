#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n == 1) {
    cout << "1";
    return 0;
  }
  if (n / 2 >= m) {
    cout << m + 1;
  } else {
    cout << m - 1;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long fb[100005] = {};
const int mm = 1000000007;
int main() {
  int m, n;
  cin >> m >> n;
  fb[1] = 1;
  fb[2] = 2;
  for (int i = 3; i <= max(m, n); i++) {
    fb[i] = (fb[i - 1] + fb[i - 2]) % mm;
  }
  cout << (fb[m] + fb[n] - 1) * 2 % mm;
  return 0;
}

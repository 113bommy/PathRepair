#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, n, k;
  cin >> m >> n >> k;
  cout << (m / k + (m % k == 0 ? 0 : 1)) * (n / k + (n % k == 0 ? 0 : 1));
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, k, s, min, max;
  cin >> n >> k;
  if (n > k)
    cout << n / k;
  else
    cout << k / n;
  return 0;
}

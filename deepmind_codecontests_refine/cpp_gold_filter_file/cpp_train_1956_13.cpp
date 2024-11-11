#include <bits/stdc++.h>
using namespace std;

int main() {
  long n, k;

  cin >> n >> k;

  cout << min(n % k, k - n % k);

  return 0;
}
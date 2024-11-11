#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  n = n / k;
  if (n % 2 == 0)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}

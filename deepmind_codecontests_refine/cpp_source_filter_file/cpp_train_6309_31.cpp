#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (floor(n / k) == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

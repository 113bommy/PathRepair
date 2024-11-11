#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if ((n / k) % 2 != 0)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

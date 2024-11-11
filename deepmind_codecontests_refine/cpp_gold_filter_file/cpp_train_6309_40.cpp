#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if ((n / k) % 2 == 1)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}

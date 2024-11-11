#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (n % (2 * k) >= k)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}

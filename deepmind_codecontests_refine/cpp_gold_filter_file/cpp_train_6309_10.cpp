#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if ((n / k) % 2 == 0)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}

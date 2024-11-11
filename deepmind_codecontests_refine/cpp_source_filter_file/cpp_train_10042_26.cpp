#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  n *= 2;
  int s = sqrt(n);
  if (s * (s + 1) == n && n > 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}

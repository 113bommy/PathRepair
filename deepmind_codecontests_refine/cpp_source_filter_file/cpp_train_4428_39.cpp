#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a;
  cin >> n;
  if (n != 0)
    a = (3 * (n - 1) * n) + 1;
  else
    a = 0;
  cout << a;
}

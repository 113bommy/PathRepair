#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, a;
  cin >> n >> m;
  if (m - 1 >= (n - m))
    a = m - 1;
  else
    a = m + 1;
  if (n == 1) a = 1;
  cout << a << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a;
  long long col = 0;
  cin >> n >> m >> a;
  if (n % a == 0)
    col = n / a;
  else
    col = n / a + 1;
  if (m % a == 0)
    col *= m / a;
  else
    col *= m / a + 1;
  cout << col << endl;
}

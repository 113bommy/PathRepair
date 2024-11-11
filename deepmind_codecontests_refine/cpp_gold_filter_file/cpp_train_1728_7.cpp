#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a;
  cin >> n;
  a = 0;
  for (int i = 1; i <= n; i++) a += i;
  if (a % (n + 1) == 0)
    cout << a / (n + 1) - 1;
  else
    cout << a / (n + 1);
}

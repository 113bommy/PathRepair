#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  cin >> n >> a >> b;
  n = n - a;
  if (b < n)
    cout << b + 1;
  else if (b > n)
    cout << n;
  else
    cout << b + b - n;
}

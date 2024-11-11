#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, n;
  cin >> n >> a;
  if (a % 2)
    cout << 1 + a / 2;
  else
    cout << 1 + (n / 2 - a / 2);
}

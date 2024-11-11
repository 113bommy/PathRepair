#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  cin >> n >> a;
  if (!(a % 2)) a = n + 1 - a;
  cout << a / 2 + 1;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int x[10] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
  int a;
  cin >> a;
  cout << x[a % 10] * x[a / 10];
  return 0;
}

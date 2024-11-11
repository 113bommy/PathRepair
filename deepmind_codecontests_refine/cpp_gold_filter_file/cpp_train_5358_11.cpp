#include <bits/stdc++.h>
using namespace std;
double const pi = 3.1415926536;
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = 1; i <= a; i++) cout << i << " ";
  cout << a + b + 1 << " ";
  for (int i = a + b; i > a; i--) cout << i << " ";
}

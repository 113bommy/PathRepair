#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int r = 1;
  while (r * 5 < n) {
    n -= r * 5;
    r *= 2;
  }
  string names[] = {"Sheldon", "leonard", "Penny", "Rajesh", "Howard"};
  cout << names[(n - 1) / r] << endl;
  return 0;
}

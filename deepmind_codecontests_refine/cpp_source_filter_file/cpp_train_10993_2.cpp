#include <bits/stdc++.h>
using namespace std;
int n, a[5], ans, x;
string name[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main() {
  cin >> n;
  while (n >= 5) {
    n -= 5;
    n /= 2;
  }
  cout << name[n];
  return 0;
}

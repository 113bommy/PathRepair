#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 1, i;
  cin >> n;
  string s[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  while (r * 5 < n) {
    n -= r * 5;
    r *= 2;
  }
  n = n - 1;
  n = n / r;
  cout << s[i] << endl;
}

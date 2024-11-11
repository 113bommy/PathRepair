#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  while (n >= 5) {
    n = n - 5;
    n = n / 2;
  }
  cout << str[n] << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, i;
string mas[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main() {
  cin >> n;
  while (n >= 5) {
    n = n - 5;
    n = n / 2;
  }
  cout << mas[n] << endl;
  return 0;
}

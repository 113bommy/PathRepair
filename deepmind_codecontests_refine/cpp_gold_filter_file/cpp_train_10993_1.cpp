#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[5][10] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  int n;
  cin >> n;
  if (n <= 5)
    cout << a[n - 1];
  else {
    while (n >= 6) {
      n = (n - 5) / 2;
    }
    cout << a[n];
  }
}

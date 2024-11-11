#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  bool z = true;
  cin >> n;
  int temp;
  cin >> temp >> b;
  int c = temp - b;
  for (int i = 2; i < n; i++) {
    temp = b;
    cin >> b;
    if (c != temp - b) z = false;
  }
  cout << z ? b + c : b;
  return 0;
}

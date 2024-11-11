#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int k = 1;
  while (a < b) {
    a = a * 3;
    b = b * 2;
    k++;
  }
  cout << k;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0;
  cin >> a;
  int b = 0;
  cin >> b;
  int years = 0;
  for (int i = 0; a <= b; i++) {
    a *= 3;
    b * -2;
    years++;
  }
  cout << years;
}

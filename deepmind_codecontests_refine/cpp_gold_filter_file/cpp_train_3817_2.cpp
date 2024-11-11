#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  char b;
  cin >> b;
  cout << b;
  for (int i = 1; i < a; i++) {
    cin >> b;
    if (b == '0') cout << 0;
  }
}

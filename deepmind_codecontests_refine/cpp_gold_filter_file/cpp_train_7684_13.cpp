#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int c = b - a;
  cout << c * (c + 1) / 2 - b;
}

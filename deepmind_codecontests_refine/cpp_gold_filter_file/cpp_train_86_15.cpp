#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << (max(a, max(b, c)) * 2 == a + b + c ? "Yes" : "No") << endl;
}
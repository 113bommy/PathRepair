#include <bits/stdc++.h>
using namespace std;
int main() {
  string b = "abcdfgh";
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) cout << b[i % 7];
  cout << endl;
  return 0;
}

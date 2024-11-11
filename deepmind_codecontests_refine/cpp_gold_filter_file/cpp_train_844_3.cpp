#include <bits/stdc++.h>
using namespace std;
int main() {
  string b = "abcd";
  int x;
  cin >> x;
  for (int i = 0; i < x; i++) cout << b[i % 4];
  cout << endl;
  return 0;
}

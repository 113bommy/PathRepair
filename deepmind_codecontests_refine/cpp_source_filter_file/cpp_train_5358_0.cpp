#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = b + 1; i <= a + b + 1; i++) cout << i << " ";
  for (int i = 1; i <= b; i++) cout << i << " ";
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  if (min(a, b) & 1)
    cout << "Akshat\n";
  else
    cout << "Malvika\n";
  return 0;
}

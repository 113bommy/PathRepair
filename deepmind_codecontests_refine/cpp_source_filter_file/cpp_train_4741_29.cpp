#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 3 == 0)
    cout << (n * 2) / 3;
  else
    cout << (n * 2) / 3 + 1;
  return 0;
}

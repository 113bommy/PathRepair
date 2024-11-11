#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n % 3 == 0 || n % 4 == 0)
    cout << 0;
  else
    cout << 1;
  return 0;
}

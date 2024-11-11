#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n == 0)
    cout << 1;
  else
    cout << (n * (n + 1)) * 3 + 1;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  if (n % 3 == 2)
    cout << 1 << " " << 2 << " " << n - 3 << endl;
  else
    cout << 1 << " " << 1 << " " << n - 2 << endl;
  return 0;
}

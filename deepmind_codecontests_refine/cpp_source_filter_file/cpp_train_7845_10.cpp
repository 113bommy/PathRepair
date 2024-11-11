#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int a;
    cin >> a;
    if (180 % (180 - a) == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

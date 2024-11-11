#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  if (n > 2)
    cout << n - 2 << endl;
  else if (n <= 2)
    cout << n + 2 << endl;
  return 0;
}

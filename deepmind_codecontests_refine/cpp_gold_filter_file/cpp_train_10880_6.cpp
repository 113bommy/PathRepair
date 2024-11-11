#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  if (n % 4 == 0)
    cout << (n / 4) - 1 << endl;
  else if (n % 2 == 0)
    cout << (n / 4) << endl;
  else
    cout << "0" << endl;
  return 0;
}

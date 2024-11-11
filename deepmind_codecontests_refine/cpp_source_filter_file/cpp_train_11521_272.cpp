#include <bits/stdc++.h>
using namespace std;
int main() {
  long a, n;
  cin >> n;
  if (n == 1)
    cout << "Ehab";
  else if (n == 2)
    cout << "Mahmoud";
  else if (n % 2 == 0)
    cout << "Mahmoud";
  else if (n % 3 == 0)
    cout << "Ehab";
  return 0;
}

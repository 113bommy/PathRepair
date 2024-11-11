#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 1)
    cout << "1" << endl;
  else if (n == 2)
    cout << "2" << endl;
  else if (n == 3)
    cout << "6" << endl;
  else {
    if (n % 2 == 1)
      cout << n * (n - 1) * (n - 2) << endl;
    else {
      if (n % 3 == 0) {
        n--;
        cout << n * (n - 1) * (n - 2) << endl;
      } else
        cout << n * (n - 1) * (n - 3) << endl;
    }
  }
}

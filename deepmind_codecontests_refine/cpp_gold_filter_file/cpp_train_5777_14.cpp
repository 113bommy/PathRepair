#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << "1\n1" << endl;
  } else if (n == 3)
    cout << "2\n1 3" << endl;
  else if (n == 4)
    cout << "4\n3 1 4 2" << endl;
  else {
    cout << n << endl;
    for (int i = 0; 2 * i + 1 <= n; i++) {
      if (i != 0) cout << " ";
      cout << 2 * i + 1;
    }
    for (int i = 1; 2 * i <= n; i++) cout << " " << 2 * i;
    cout << endl;
  }
  return 0;
}

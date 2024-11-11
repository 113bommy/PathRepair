#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 != 0)
    cout << "-1" << endl;
  else {
    cout << "2 1";
    for (int i = 3; i < n; i++) {
      cout << " " << i + 1 << " " << i;
    }
  }
  cout << endl;
  return 0;
}

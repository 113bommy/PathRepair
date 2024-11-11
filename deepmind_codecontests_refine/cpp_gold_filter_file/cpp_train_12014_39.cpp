#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x = 500000;
  cout << x++;
  n--;
  while (n) {
    cout << " " << x;
    x++;
    n--;
  }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << "YES" << endl;
  cout << "0 0" << endl;
  int x = 0, dx = 1;
  for (int i = 1; i < n - 1; i++) {
    x += dx;
    printf("%d 0\n", x);
    dx++;
  }
  cout << "100000000 100000000" << endl;
}

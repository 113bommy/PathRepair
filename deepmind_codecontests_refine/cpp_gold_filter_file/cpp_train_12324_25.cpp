#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[3];
  int x = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int i = 0; i < 3; i++) {
      cin >> a[i];
    }
    if (a[1] == '+') {
      x++;
    } else {
      x--;
    }
  }
  cout << x << endl;
  return 0;
}

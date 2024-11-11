#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
  cin >> n;
  for (int i = 0; i < 14; i++) {
    if (n % a[i]) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}

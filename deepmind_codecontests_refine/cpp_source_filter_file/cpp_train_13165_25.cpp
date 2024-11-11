#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[10] = {2, 7, 2, 3, 3, 3, 2, 5, 1, 2};
  char c, c1;
  cin >> c >> c1;
  cout << arr[c - '0'] * arr[c1 - '0'] << endl;
  return 0;
}

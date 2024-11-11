#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};
  char str[2];
  cin >> str;
  cout << (arr[str[0] - '0'] * arr[str[1] - '0']) << endl;
  return 0;
}

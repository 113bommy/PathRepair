#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[4] = {2, 4, 6, 8};
  int n;
  cin >> n;
  if (n == 0) {
    cout << 1;
    return 0;
  } else
    cout << arr[n % 4] << endl;
  return 0;
}

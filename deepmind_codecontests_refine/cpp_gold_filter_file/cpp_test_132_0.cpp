#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[8];
  int test;
  cin >> test;
  int i;
  for (i = 0; i < test; i++) {
    for (int j = 0; j < 7; j++) {
      cin >> arr[j];
    }
    cout << arr[0] << " " << arr[1] << " " << arr[6] - arr[0] - arr[1] << "\n";
  }
  return 0;
}

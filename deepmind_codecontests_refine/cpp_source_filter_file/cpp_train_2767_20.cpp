#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[3] = {0};
  long long n;
  cin >> n;
  int x;
  cin >> x;
  arr[x] = 1;
  for (int i = n % 5; i > 0; i--) {
    if (i & 1) {
      int temp = arr[0];
      arr[0] = arr[1];
      arr[1] = temp;
    } else {
      int temp = arr[2];
      arr[2] = arr[1];
      arr[1] = temp;
    }
  }
  for (int i = 0; i < 3; i++) {
    if (arr[i] == 1) {
      cout << i << endl;
      return 0;
    }
  }
}

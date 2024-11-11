#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n], a = 0, b = 0;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    if (arr[i] == 5) {
      a++;
    } else
      b++;
  }
  int x = a / 9;
  if (b == 0)
    cout << -1;
  else if (x == 0)
    cout << 0;
  else {
    for (int i = 0; i < a; i++) {
      cout << 5;
    }
    for (int i = 0; i < b; i++) {
      cout << 0;
    }
  }
  return 0;
}

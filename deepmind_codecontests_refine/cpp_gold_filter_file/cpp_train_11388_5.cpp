#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[1000];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int counter = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1])
      counter++;
    else {
      counter = 1;
    }
    if (n == 2 && counter == 2) {
      cout << "NO\n";
      return 0;
    } else if (counter > ((n % 2 == 0) ? (n / 2) : ((n / 2) + 1))) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  return 0;
}

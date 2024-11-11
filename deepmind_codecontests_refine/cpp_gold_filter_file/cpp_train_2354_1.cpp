#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, temp = 0;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 1) {
      temp++;
    }
  }
  if (temp > 0) {
    cout << "First";
  } else {
    cout << "Second";
  }
  return 0;
}

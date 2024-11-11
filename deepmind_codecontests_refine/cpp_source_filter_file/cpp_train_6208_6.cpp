#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[6];
  int sum = 0;
  for (int i = 0; i < 6; ++i) {
    cin >> arr[i];
    sum += arr[i];
  }
  if (sum % 2 == 1) {
    cout << "NO";
    return 0;
  }
  int psum = sum / 2, ans = arr[0];
  for (int i = 1; i < 5; ++i) {
    for (int j = i + 1; i < 6; ++i)
      if (ans + arr[i] + arr[j] == psum) {
        cout << "YES";
        return 0;
      }
  }
  cout << "NO";
}

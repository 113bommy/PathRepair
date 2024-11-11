#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (arr[0] % 2 == 0 || n % 2 == 0 || arr[n - 1] == 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  int left = -1, right = -1;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr[i] = num;
    if (i != 0) {
      if (arr[i] < arr[i - 1]) {
        if (left == -1) {
          left = i - 1;
        }
      } else {
        if (right == -1 && left != -1) {
          right = i - 1;
        }
      }
    }
  }
  if (left == -1 && right == -1) {
    cout << "Yes" << endl;
    cout << "1 1" << endl;
    return 0;
  }
  if (left != -1 && right == -1) {
    reverse(arr.begin() + left, arr.end());
  } else {
    reverse(arr.begin() + left, arr.begin() + right + 1);
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  if (right == -1) {
    cout << left + 1 << " " << n << endl;
  } else {
    cout << left + 1 << " " << right + 1 << endl;
  }
  return 0;
}

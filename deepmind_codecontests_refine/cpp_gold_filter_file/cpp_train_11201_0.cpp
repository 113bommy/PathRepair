#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int arr[1000][2];
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> arr[i][j];
    }
  }
  bool a = true;
  for (int i = 0; i < t; i++) {
    if (arr[i][0] != arr[i][1]) {
      a = false;
      cout << "rated";
      exit(0);
    }
  }
  for (int i = 0; i < t; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[i][0] > arr[j][0]) {
        cout << "unrated";
        a = false;
        exit(0);
      }
    }
  }
  if (a) {
    cout << "maybe";
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n][2];
  int min = 1000000001, max = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
    if (arr[i][0] < min) {
      min = arr[i][0];
    }
    if (arr[i][1] > max) {
      max = arr[i][1];
    }
  }
  vector<int> i1, i2;
  for (int i = 0; i < n; i++) {
    if (arr[i][0] == min) {
      i1.push_back(i);
    }
    if (arr[i][1] == max) {
      i2.push_back(i);
    }
  }
  for (int i = 0; i < i1.size(); i++) {
    for (int j = 0; j < i2.size(); j++) {
      if (i1[i] == i2[j]) {
        cout << i1[i] + 1 << '\n';
        return 0;
      }
    }
  }
  cout << -1 << '\n';
}

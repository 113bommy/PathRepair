#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, h, sum = 0;
  cin >> n >> h;
  int arr[n];
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] > h) {
      sum += 2;
    } else {
      sum += 1;
    }
  }
  cout << sum;
}

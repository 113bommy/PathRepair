#include <bits/stdc++.h>
using namespace std;
int n = 0, k = 0;
int arr[100];
int main() {
  int r = 0;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] >= arr[k] and arr[i] > 0) {
      r++;
    }
  }
  cout << r;
}

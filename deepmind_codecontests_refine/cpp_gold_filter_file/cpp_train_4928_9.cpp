#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  int arr[100000];
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int k = arr[b];
  int l = arr[b - 1];
  cout << k - l << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[m];
  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;
    arr[i] = temp;
  }
  int middle = 1001;
  sort(arr, arr + m);
  for (int i = 0; i <= (m - n); i++) {
    middle = min(arr[i + n - 1] - arr[i], middle);
  }
  cout << middle;
}

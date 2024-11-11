#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n;
  int m;
  cin >> n >> m;
  long int arr[m];
  memset(arr, 0, sizeof arr);
  long int temp;
  for (long int i = 0; i < n; i++) {
    cin >> temp;
    arr[temp - 1]++;
  }
  unsigned long int ans = n * n;
  for (int i = 0; i < m; i++) {
    ans -= arr[i] * arr[i];
  }
  cout << ans / 2;
}

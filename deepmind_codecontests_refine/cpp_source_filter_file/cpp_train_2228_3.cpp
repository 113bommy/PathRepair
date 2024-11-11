#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int arr[m];
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + m);
  int mindiff = INT_MAX;
  int i = 0;
  int j = n - 1;
  while (j < m - 1) {
    mindiff = min(mindiff, arr[j] - arr[i]);
    i++;
    j++;
  }
  cout << mindiff;
}

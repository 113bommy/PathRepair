#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int sum = 0;
  for (int i = 0; i < n; i++)
    if (arr[i] < 0) sum -= arr[i];
  cout << sum << endl;
  return 0;
}

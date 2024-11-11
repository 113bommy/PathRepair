#include <bits/stdc++.h>
using namespace std;
double PI = 4.00 * (atan(1));
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int arr1[n];
  for (long long int i = 0; i < n; i++) {
    cin >> arr1[i];
  }
  long long int ans[n];
  long long int pos1 = 0, pos2 = n - 1;
  sort(arr1, arr1 + n);
  for (long long int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      ans[pos1] = arr1[i];
      pos1++;
    } else {
      ans[pos2] = arr1[i];
      pos2--;
    }
  }
  for (long long int i = 0; i < n; i++) {
    cout << arr1[i] << " ";
  }
  return 0;
}

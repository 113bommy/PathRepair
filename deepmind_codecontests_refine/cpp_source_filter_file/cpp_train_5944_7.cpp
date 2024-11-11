#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int arr[n];
  long long int max = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > max) max = arr[i];
  }
  for (long long int j = 0; j < n; j++) {
    if (j % 2 == 0) arr[j]--;
  }
  for (long long int i = 0; i < n; i++) cout << arr[i] << " ";
  return 0;
}

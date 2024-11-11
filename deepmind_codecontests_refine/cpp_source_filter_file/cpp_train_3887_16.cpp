#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, sum;
  cin >> n;
  long long int arr[n];
  sum = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr + n);
  long long int curr = 0;
  long long int cnt = 0;
  long long int ind = n - 1;
  while (curr <= sum) {
    ++cnt;
    curr += arr[ind];
    sum -= curr;
    --ind;
  }
  cout << cnt << "\n";
  return 0;
}

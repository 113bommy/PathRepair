#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, sum, m, n, s;
  cin >> s;
  long long arr[2 * s];
  for (i = 0; i < 2 * s; i++) cin >> arr[i];
  sort(arr, arr + (2 * s));
  sum = (arr[2 * s - 1] - arr[s]) * (arr[s - 1] - arr[0]);
  for (i = 0; i < s; i++) {
    sum = min(sum, (arr[2 * s - 1] - arr[0]) * arr[n + i - 1] - arr[i]);
  }
  cout << sum;
  return 0;
}

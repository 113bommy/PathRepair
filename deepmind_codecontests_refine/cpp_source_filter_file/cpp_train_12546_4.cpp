#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N, i, count = 0, sum = 0, j = 0;
  cin >> N;
  long long int arr[N];
  for (i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 0)
      sum += arr[i];
    else
      count++;
  }
  sort(arr, arr + N);
  i = N - 1;
  if (count % 2 != 0) count -= 1;
  while (i >= 0) {
    if (arr[i] % 2 != 0) {
      sum = sum + arr[i];
      j++;
    }
    i--;
    if (j == count) break;
  }
  cout << sum;
  return 0;
}

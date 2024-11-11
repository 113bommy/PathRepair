#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, i;
  long long x, sum = 0, avg = 0, count = 0;
  cin >> T;
  long long arr[T + 1];
  for (i = 1; i <= T; i++) {
    cin >> arr[i];
    sum = sum + arr[i];
  }
  avg = (sum / T);
  for (i = 1; i <= T; i++) {
    count = count + abs(arr[i] - avg);
    arr[i + 1] = arr[i + 1] + (arr[i] - avg);
  }
  cout << count << endl;
  return 0;
}

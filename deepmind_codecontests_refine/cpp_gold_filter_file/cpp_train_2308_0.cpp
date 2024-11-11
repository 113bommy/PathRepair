#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c, d, num = 0;
  int arr[3];
  cin >> arr[0] >> arr[1] >> arr[2] >> d;
  sort(arr, arr + 3);
  if (arr[1] - arr[0] < d) num = d - (arr[1] - arr[0]);
  if (arr[2] - arr[1] < d) num += d - (arr[2] - arr[1]);
  cout << num;
}

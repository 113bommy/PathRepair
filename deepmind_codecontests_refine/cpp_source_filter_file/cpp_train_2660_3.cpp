#include <bits/stdc++.h>
using namespace std;
void input(vector<long long> &arr, long long n) {
  for (long long i = 0; i < n; i++) cin >> arr[i];
}
long long sumarr(vector<long long> &arr, long long n) {
  long long sum = 0;
  for (long long i = 0; i < n; i++) sum += arr[i];
  return sum;
}
vector<long long> prearr(vector<long long> &arr, long long n) {
  vector<long long> temp(n);
  temp[0] = arr[0];
  for (long long i = 1; i < n; i++) temp[i] = temp[i - 1] + arr[i];
  return temp;
}
vector<long long> postarr(vector<long long> &arr, long long n) {
  vector<long long> temp(n);
  temp[n - 1] = arr[n - 1];
  for (long long i = n - 2; i >= 0; i--) temp[i] = temp[i + 1] + arr[i];
  return temp;
}
int32_t main() {
  long long tt = 1;
  while (tt--) {
    long long n = 4;
    long long arr[4];
    for (long long i = 0; i < 4; i++) cin >> arr[i];
    sort(arr, arr + n);
    long long flag = 0;
    if (arr[0] + arr[1] > arr[2]) flag = 1;
    if (arr[2] + arr[1] > arr[3]) flag = 1;
    if (flag == 1) {
      cout << "TRIANGLE";
      return 0;
    }
    if (arr[0] + arr[1] == arr[2]) flag = 2;
    if (arr[2] + arr[1] > arr[3]) flag = 2;
    if (flag == 2) {
      cout << "SEGMENT";
      return 0;
    }
    cout << "IMPOSSIBLE";
  }
  return 0;
}

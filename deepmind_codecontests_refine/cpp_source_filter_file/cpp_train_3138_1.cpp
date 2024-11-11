#include <bits/stdc++.h>
using namespace std;
int arr[5 * 10004];
int power[105];
bool status[105];
void siv() {
  int N = 100;
  int sq = sqrt(N);
  for (int i = 4; i <= N; i += 2) status[i] = 1;
  for (int i = 3; i <= sq; i += 2) {
    if (status[i] == 0) {
      for (int j = i * i; j <= N; j += i) status[j] = 1;
    }
  }
  status[1] = 1;
  status[3] = 1;
}
int main() {
  int i, j, k, l, n, m, sum = 0, l1, l2;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    sum += arr[i];
  }
  siv();
  k = sum;
  sort(arr, arr + n);
  l = 0;
  int mx = INT_MAX;
  for (i = n - 1; i >= 1; i--) {
    if (status[arr[i]] == 1) {
      sum = k;
      for (j = 2; j <= sqrt(arr[i]); j++) {
        sum = k;
        if (arr[i] % j == 0) {
          m = j;
          l1 = (arr[i]) / j;
          l2 = (arr[i] - l1);
          sum -= l2;
          l1 = arr[0] * j;
          l2 = l1 - arr[0];
          sum += l2;
          if (sum < mx) mx = sum;
          sum = k;
          m = arr[i] / j;
          l1 = arr[i] / j;
          l2 = (arr[i] - l1);
          sum -= l2;
          l1 = arr[0] * j;
          l2 = l1 - arr[0];
          sum += l2;
          if (sum < mx) mx = sum;
        }
      }
    }
  }
  cout << mx << endl;
}

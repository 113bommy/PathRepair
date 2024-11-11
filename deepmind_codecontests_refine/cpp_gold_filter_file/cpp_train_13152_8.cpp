#include <bits/stdc++.h>
using namespace std;
int arr[3];
int a[4001];
int n;
int f(int sum) {
  if (sum == n) return 0;
  if (sum > n) return -1;
  if (a[sum] > -2) return a[sum];
  int max = -2;
  for (int i = 0; i < 3; ++i) {
    int ss = f(arr[i] + sum) + 1;
    if (ss == 0) ss = -1;
    if (max < ss) max = ss;
  }
  return a[sum] = max;
}
int main() {
  while (cin >> n >> arr[0] >> arr[1] >> arr[2]) {
    memset(a, -2, sizeof a);
    cout << f(0) << endl;
  }
  return 0;
}

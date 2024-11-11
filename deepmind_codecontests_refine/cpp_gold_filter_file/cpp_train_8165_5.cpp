#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  long long arr[100002] = {0};
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x] += x;
  }
  for (int i = 2; i < 100002; i++) {
    arr[i] = max(arr[i - 1], arr[i - 2] + arr[i]);
  }
  cout << arr[100001];
  return 0;
}

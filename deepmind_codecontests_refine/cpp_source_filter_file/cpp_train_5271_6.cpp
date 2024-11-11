#include <bits/stdc++.h>
using namespace std;
using std::cin;
using std::cout;
long long MOD = 998244353;
bool check(int mid, int arr[], int n, int k) {
  int size[n + 1];
  int idx = 0;
  for (int i = 0; i <= n; i++) size[i] = 0;
  for (int i = k; i <= n; i++) {
    if (arr[i] - arr[1 + size[i - k]] <= mid) {
      idx = i;
    }
    size[i] = idx;
  }
  if (size[n] == n) return true;
  return false;
}
int main() {
  int n, k;
  cin >> n >> k;
  int arr[n + 1];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  sort(arr + 1, arr + n + 1);
  int left = 0;
  int right = 1e6;
  while (left < right) {
    int mid = (left + right) / 2;
    if (check(mid, arr, n, k)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  cout << left << "\n";
  return 0;
}

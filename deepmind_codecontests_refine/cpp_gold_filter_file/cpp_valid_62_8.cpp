#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int fun(int arr[], int n, int i, int j) {
  int ma = INT_MIN;
  int alpha = 0;
  for (int l = i; l <= j; l++) {
    arr[l] = arr[l] & arr[i + j - l];
  }
  for (int i = 0; i < n; i++) {
    ma = max(ma, arr[i]);
  }
  return ma;
}
void solve() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (arr[n - 1] == 0) {
    for (int i = 0; i < n + 1; i++) {
      cout << i + 1 << " ";
    }
    cout << endl;
  } else {
    int i;
    for (i = n - 2; i >= 0; i--) {
      if (arr[i] == 0) {
        break;
      }
    }
    if (i == -1) {
      cout << n + 1 << " ";
      for (int j = 0; j < n; j++) {
        cout << j + 1 << " ";
      }
      cout << endl;
    } else {
      for (int j = 0; j <= i; j++) {
        cout << j + 1 << " ";
      }
      cout << n + 1 << " ";
      for (int j = i + 1; j < n; j++) {
        cout << j + 1 << " ";
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  std::cout.unsetf(std::ios::fixed);
  std::cout.precision(9);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

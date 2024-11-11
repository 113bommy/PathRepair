#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int maxx = abs(arr[0]), cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    maxx += abs(arr[i] - arr[i + 1]);
  }
  cout << maxx;
  return 0;
}

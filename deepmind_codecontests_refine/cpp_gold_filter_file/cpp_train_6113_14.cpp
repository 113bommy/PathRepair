#include <bits/stdc++.h>
using namespace std;
int arr[100];
int arr2[200];
int main() {
  int n, x;
  cin >> n >> x;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= x; i++) cin >> arr2[i];
  sort(arr2 + 1, arr2 + x + 2, greater<int>());
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= x; j++) {
      if (arr[i] == arr2[j]) cout << arr2[j] << " ";
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
int arr[100100];
int ans[100100];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    arr[i]--;
  }
  int z = unique(arr, arr + n) - arr;
  for (int i = 0; i < z; i++) {
    int c = 0;
    if (i > 0) {
      c++;
    }
    if (i < z - 1) {
      c++;
    }
    if (i > 0 && i < z - 1 && arr[i - 1] != arr[i + 1]) {
      c--;
    }
    ans[arr[i]] += c;
  }
  cout << max_element(ans, ans + k) - ans + 1;
}

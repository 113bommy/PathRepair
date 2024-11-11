#include <bits/stdc++.h>
using namespace std;
long long GCD(long long x, long long y) { return !y ? x : GCD(y, x % y); }
long long LCM(long long x, long long y) { return x * y / GCD(x, y); }
int arr1[100], arr2[100];
int main() {
  ios::sync_with_stdio(false);
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr1[i], arr2[i] = arr1[i];
  sort(arr2, arr2 + n);
  for (int i = n - 1; i >= 0; i--)
    if (arr2[i] != arr1[i])
      for (int j = i - 1; j >= 0; j--)
        if (arr1[j] == arr2[i]) {
          for (int k = j; k < i; k++) {
            swap(arr1[k], arr1[k + 1]);
            cout << k + 1 << " " << k + 2 << "\n";
          }
          break;
        }
  return 0;
}

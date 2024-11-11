#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 1];
  int number;
  for (int i = 0; i != n; i++) {
    cin >> number;
    arr[number] = i;
  }
  int m;
  cin >> m;
  long long res = 0, res2 = 0;
  int arr2[m];
  for (int i = 0; i != m; i++) {
    cin >> arr2[i];
    res += arr[arr2[i]] + 1;
    res2 += (n - arr[arr2[i]]);
  }
  cout << res << " " << res2;
  return 0;
}

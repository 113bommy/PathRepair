#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) {
    while (arr[i] % 2 == 0) arr[i] /= 2;
    while (arr[i] % 3 == 0) arr[i] /= 3;
  }
  for (int i = 2; i < n; i++)
    if (arr[0] != arr[i]) {
      cout << "No\n";
      return 0;
    }
  cout << "Yes";
  return 0;
}

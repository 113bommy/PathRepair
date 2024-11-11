#include <bits/stdc++.h>
using namespace std;
void MAIN() {
  int n;
  cin >> n;
  int arr[n];
  for (int &i : arr) cin >> i;
  sort(arr, arr + n);
  int ans = 0;
  int c = 0;
  for (int i : arr) {
    c++;
    if (c == i) {
      ans++;
      c = 0;
    }
  }
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) MAIN();
}

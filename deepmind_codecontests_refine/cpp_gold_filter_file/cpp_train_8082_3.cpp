#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(00), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int arr[n];
  int count1 = 0, count2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] % 2 == 0) {
      count1++;
    } else {
      count2++;
    }
  }
  int x = min(count1, count2);
  int y = count2 - x;
  cout << x + (y / 3) << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  int arr[n];
  int pos = 0;
  int neg = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    if (arr[i] > 0) pos++;
    if (arr[i] < 0) neg++;
  }
  if (pos < ceil((double)n / 2) && neg < ceil((double)n / 2)) {
    cout << "0\n";
  } else {
    if (pos >= ceil((double)n / 2)) {
      for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
          cout << arr[i] << '\n';
          break;
        }
      }
    } else if (neg >= ceil((double)n / 2)) {
      for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
          cout << arr[i] << '\n';
          break;
        }
      }
    }
  }
  return 0;
}

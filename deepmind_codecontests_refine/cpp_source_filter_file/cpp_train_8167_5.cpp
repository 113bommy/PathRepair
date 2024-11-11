#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a;
  cin >> n >> a;
  long long int k = 0;
  long long int arr[n];
  for (k = 0; k < n - 1; k++) cin >> arr[k];
  int j = 0;
  k = 0;
  while (k < a) {
    if (k == a - 1) {
      cout << "YES";
      break;
    } else {
      k = k + arr[k];
    }
  }
  if (k == a) cout << "NO";
  return 0;
}

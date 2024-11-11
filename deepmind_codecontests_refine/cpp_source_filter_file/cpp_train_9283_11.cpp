#include <bits/stdc++.h>
using namespace std;
using L = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  L n;
  cin >> n;
  if (n % 2 == 0) {
    cout << "No";
    return 0;
  }
  L i = 2, arr[2 * n];
  arr[0] = 1;
  arr[1] = 2 * n;
  while (i <= n) {
    arr[i] = arr[i - 1] - 3;
    arr[i + 1] = arr[i] - 1;
    i += 2;
  }
  if (n >= 3) {
    arr[n + 1] = 2 * n - 1;
    arr[n + 2] = 2 * n - 2;
    i += 2;
  }
  while (i < 2 * n - 1) {
    arr[i] = arr[i - 1] - 3;
    arr[i + 1] = arr[i] - 1;
    i += 2;
  }
  cout << "Yes" << endl;
  for (L i = 0; i < 2 * n; ++i) {
    cout << arr[i] << " ";
  }
  return 0;
}

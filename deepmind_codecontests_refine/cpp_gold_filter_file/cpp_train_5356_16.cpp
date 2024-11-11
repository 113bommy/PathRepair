#include <bits/stdc++.h>
using namespace std;
int arr[1000];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  memset(arr, -1, sizeof(arr));
  int p, n;
  cin >> p >> n;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    tmp = tmp % p;
    if (~arr[tmp]) {
      cout << i + 1 << '\n';
      return 0;
    }
    arr[tmp] = 1;
  }
  cout << "-1\n";
  return 0;
}

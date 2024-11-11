#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, M = 1e7, OO = 0x3f3f3f3f;
const long long int MOD = 1e9 + 7;
int main() {
  int n;
  scanf("%d", &n);
  long long int arr[N];
  for (int i = 0; i < int(n); ++i) {
    cin >> arr[i];
    arr[i] += 1e6;
  }
  cout << n + 1 << '\n';
  cout << 1 << " " << n << " " << 1000000 << '\n';
  for (int i = int(1); i <= int(n); i++) {
    cout << 2 << " " << i << " " << arr[i - 1] - i << '\n';
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int const MAXN = 100;
int n, temp;
int arr[MAXN + 1]{};
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    arr[temp]++;
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += arr[i] / 2;
  }
  cout << ans / 2 << endl;
  return 0;
}

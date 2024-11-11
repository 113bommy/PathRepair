#include <bits/stdc++.h>
using namespace std;
const int m = 2e5;
int arr[m];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  char c;
  int a, b;
  cin >> a;
  int l = 0, r = 0;
  while (a--) {
    cin >> c >> b;
    if (c == 'L')
      arr[b] = --l;
    else if (c == 'R')
      arr[b] = ++r;
    else
      cout << min(arr[b] - l, r - arr[b]) << endl;
  }
  return 0;
}

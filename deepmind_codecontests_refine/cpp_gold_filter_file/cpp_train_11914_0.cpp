#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int x = 0;
  int a = n;
  while (x < n) {
    arr[x] = 0;
    x += 1;
  }
  int m;
  cin >> n >> m;
  while (n-- > 0) {
    cin >> x;
    arr[x - 1] = 1;
  }
  while (m-- > 0) {
    cin >> x;
    arr[x - 1] = 2;
  }
  x = 0;
  while (x < a) {
    cout << arr[x] << " ";
    x += 1;
  }
}

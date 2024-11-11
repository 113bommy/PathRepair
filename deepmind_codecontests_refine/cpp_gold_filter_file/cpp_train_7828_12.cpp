#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[111] = {0}, i, j, a, x = 0, b;
  for (i = 0; i < n; i++) {
    cin >> a;
    arr[a]++;
  }
  for (i = 0; i < 111; i++) {
    a = arr[i] / 2;
    x += a;
  }
  cout << x / 2;
}

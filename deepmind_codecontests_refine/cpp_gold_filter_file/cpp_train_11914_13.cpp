#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, arr[101];
  cin >> n >> a >> b;
  for (size_t i = 0; i < a; i++) {
    int c;
    cin >> c;
    arr[c] = 1;
  }
  for (size_t i = 0; i < b; i++) {
    int c;
    cin >> c;
    arr[c] = 2;
  }
  for (size_t i = 1; i <= n; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}

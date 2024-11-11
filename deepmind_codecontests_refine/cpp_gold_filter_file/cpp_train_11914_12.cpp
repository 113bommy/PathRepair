#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int arr[122] = {0}, x;
  while (a--) {
    cin >> x;
    arr[x] = 1;
  }
  while (b--) {
    cin >> x;
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      cout << "1 ";
    } else {
      cout << "2 ";
    }
  }
  cout << endl;
  return 0;
}

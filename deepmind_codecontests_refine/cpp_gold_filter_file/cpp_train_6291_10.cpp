#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[101];
  for (int i = 0; i < n; i++) cin >> a[i];
  int min = 1 << 26;
  for (int i = 0; i < n; i++) {
    int temp = 0;
    for (int j = 0; j < a[i]; j++) {
      int t;
      cin >> t;
      temp += t * 5;
    }
    temp += a[i] * 15;
    if (min > temp) min = temp;
  }
  cout << min << endl;
  return 0;
}

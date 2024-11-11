#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[3000];
  cin >> n;
  int i;
  int j = 0;
  int temp;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) j++;
  }
  if (j == 0) {
    cout << "1";
    exit(0);
  }
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (a[j] <= a[i]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
  for (i = 0; i < n - 1; i++) {
    if (a[i + 1] - a[i] >= 1) break;
  }
  cout << a[i] + 1;
  return 0;
}

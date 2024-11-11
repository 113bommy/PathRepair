#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n], count = 0, i;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i < n - 1; i++) {
    if (a[i - 1] == 1 and a[i + 1] == 1 and a[i] == 0) {
      a[i - 1] = 0;
      count++;
    }
  }
  cout << count;
  return 0;
}

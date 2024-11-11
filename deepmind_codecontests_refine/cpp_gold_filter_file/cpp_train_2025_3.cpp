#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0, pos, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i < n; i++) {
    if (a[i - 1] > a[i]) {
      count++;
      pos = i;
    }
  }
  if (count == 1 && a[0] >= a[n - 1])
    cout << n - pos;
  else if (count == 0)
    cout << "0";
  else
    cout << "-1";
}

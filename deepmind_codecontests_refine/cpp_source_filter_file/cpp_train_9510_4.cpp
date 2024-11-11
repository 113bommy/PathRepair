#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[1000];
  int min = 2000000000;
  int count = 0;
  int x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < min) {
      min = a[i];
      x = i;
      count = 0;
    } else if (a[i] == min)
      count = count + 1;
  }
  if (count > 0)
    cout << "Still Rozdil";
  else
    cout << x;
  return 0;
}

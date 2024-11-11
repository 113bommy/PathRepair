#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int a[n];
  int max = 0;
  int index = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max) {
      max = a[i];
      index = i;
    }
  }
  int inc = 1, c = 1;
  for (int i = 0; i < n; i++) {
    if (a[i + 1] < a[i]) inc = 0;
    if (a[i + 1] > a[i] && inc == 0) {
      cout << "No" << endl;
      c = 0;
      break;
    }
  }
  if (c == 1) cout << "Yes" << endl;
}

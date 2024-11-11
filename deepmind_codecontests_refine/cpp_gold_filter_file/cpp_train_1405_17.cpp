#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const long long mod = 1000000007;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int flag1 = 1;
  int steps1;
  if (a[0] > 0) {
    steps1 = (n - a[0]);
  } else {
    steps1 = 0;
  }
  for (int i = 1; i < n; ++i) {
    int temp;
    if (i & 1) {
      if (a[i] >= i) {
        temp = a[i] - i;
      } else {
        temp = (n - (i - a[i]));
      }
    } else {
      if (a[i] > i) {
        temp = (n - (a[i] - i));
      } else {
        temp = (i - a[i]);
      }
    }
    if (temp != steps1) {
      flag1 = 0;
    }
  }
  if (flag1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}

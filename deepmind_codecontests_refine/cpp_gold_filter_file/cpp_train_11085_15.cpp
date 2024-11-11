#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int count = 1;
  int temp = 1;
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == a[i + 1]) {
      temp++;
      if (temp > count) {
        count = temp;
      }
    } else {
      if (temp > count) {
        count = temp;
      }
      temp = 1;
    }
  }
  cout << n - count;
}

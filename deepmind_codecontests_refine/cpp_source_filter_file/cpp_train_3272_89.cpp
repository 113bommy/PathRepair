#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int temp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (a[i] > a[j]) {
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}

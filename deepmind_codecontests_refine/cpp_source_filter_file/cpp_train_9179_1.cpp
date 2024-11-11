#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[200000];
  int n;
  int k = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i += 2) {
    if (a[i] == a[i + 1]) {
      if (a[i] == 'a') {
        a[i] == 'b';
        k++;
      } else {
        a[i] == 'a';
        k++;
      }
    }
  }
  cout << k << endl;
  for (int i = 0; i < n; i++) {
    cout << a[i];
  }
}

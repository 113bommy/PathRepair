#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, c = 0, x;
  cin >> n;
  if (n == 1) {
    cin >> x;
    cout << "0";
  } else {
    int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    int choto = 0;
    int boro = 0;
    for (i = 0; i < n; i++) {
      if (a[i] < choto) {
        c++;
        choto = a[i];
      }
      if (a[i] > boro) {
        c++;
        boro = a[i];
      }
    }
    cout << c;
  }
  return 0;
}

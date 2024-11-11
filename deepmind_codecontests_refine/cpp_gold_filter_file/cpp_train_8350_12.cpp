#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a[t], b[t];
  for (int i = 0; i < t; i++) {
    cin >> a[i] >> b[i];
    int k = (24 - a[i]) * 60 - b[i];
    cout << k << endl;
  }
}

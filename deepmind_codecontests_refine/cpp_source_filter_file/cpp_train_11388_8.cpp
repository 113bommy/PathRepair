#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int b[1000];
  for (int i = 0; i < 1000; i++) b[i] = 0;
  for (int i = 0; i < n; i++) b[a[i]]++;
  int x = (n + 1) / 2;
  for (int i = 0; i < 1000; i++) {
    if (b[i] != 0) {
      if (b[i] > x) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES ";
}

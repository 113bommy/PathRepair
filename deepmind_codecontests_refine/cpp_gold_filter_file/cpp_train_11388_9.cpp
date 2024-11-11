#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for (int i = 1; i <= 1000; i++) {
    if (a[i] > (n + 1) / 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}

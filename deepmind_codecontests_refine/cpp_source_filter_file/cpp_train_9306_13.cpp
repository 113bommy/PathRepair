#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int d;
  cin >> d;
  int a[1001];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int sol1 = a[i];
      int sol2 = a[j];
      if (abs(sol2 - sol1) <= d) {
        cnt++;
      }
    }
  }
  cout << cnt;
}

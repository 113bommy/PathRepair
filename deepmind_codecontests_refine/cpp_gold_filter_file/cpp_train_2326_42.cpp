#include <bits/stdc++.h>
using namespace std;
int a[2001];
int main() {
  int d, n;
  cin >> d >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int cnt = 0;
  for (int i = 0; i < n - 1; i++) {
    cnt += d - a[i];
  }
  cout << cnt;
}

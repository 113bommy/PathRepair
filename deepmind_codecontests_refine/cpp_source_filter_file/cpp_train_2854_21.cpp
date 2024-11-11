#include <bits/stdc++.h>
using namespace std;
int main() {
  int ar[100100];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
  }
  int cnt = 2;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  int mx = 0;
  for (int i = 2; i < n; i++) {
    if (ar[i - 1] + ar[i - 2] == ar[i]) {
      cnt++;
    } else {
      mx = max(cnt, mx);
      cnt = 2;
    }
  }
  cout << cnt;
}

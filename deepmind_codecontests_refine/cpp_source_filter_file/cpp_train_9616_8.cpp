#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int cnt1 = 0;
  int cnt2 = 0;
  int c = 0;
  int d = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    cnt1 += (a % 2 == 0);
    if (a % 2 == 0) {
      c = a;
    }
    cnt2 += (a % 2 == 1);
    if (a % 2 == 1) {
      d = a;
    }
  }
  if (cnt1 == n - 1) {
    cout << d << "\n";
  } else {
    cout << c << "\n";
  }
  return 0;
}

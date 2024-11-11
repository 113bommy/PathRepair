#include <bits/stdc++.h>
using namespace std;
int n, temp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int cnt = 0, a = 0, b = 0, c = 0;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    cnt++;
    if (cnt == 1) {
      a += temp;
    } else if (cnt == 2) {
      b += temp;
    } else if (cnt == 3) {
      c += temp;
    }
    if (cnt == 3) {
      cnt = 0;
    }
  }
  int maxx = max(a, max(b, c));
  if (maxx == a) {
    cout << "chest\n";
  } else if (maxx == b) {
    cout << "biceps\n";
  } else if (maxx == c) {
    cout << "back\n";
  }
}

#include <bits/stdc++.h>
using namespace std;
int n, a[105];
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    int p = -1;
    for (int j = i; j < n; ++j) {
      if (p == -1 || a[p] > a[j]) p = j;
    }
    if (p == -1) continue;
    while (p != i) {
      cout << p << ' ' << p + 1 << '\n';
      swap(a[p - 1], a[p]);
      p--;
    }
  }
}

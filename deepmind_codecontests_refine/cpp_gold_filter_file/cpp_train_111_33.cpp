#include <bits/stdc++.h>
using namespace std;
const int Maxn = 130;
int n, maxx, a[Maxn], you, she;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    she += a[i];
    maxx = max(a[i], maxx);
  }
  for (int i = maxx; i < 250; i++) {
    you = i * n - she;
    if (she < you) {
      cout << i;
      return 0;
    }
  }
}

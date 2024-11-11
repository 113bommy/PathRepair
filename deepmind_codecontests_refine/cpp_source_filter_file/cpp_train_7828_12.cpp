#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 + 321;
long long a[maxN];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int d;
    cin >> d;
    a[d]++;
  }
  int ans = 0;
  for (int i = 1; i < 100; i++) ans += a[i] / 2;
  cout << ans / 2 << endl;
  return 0;
}

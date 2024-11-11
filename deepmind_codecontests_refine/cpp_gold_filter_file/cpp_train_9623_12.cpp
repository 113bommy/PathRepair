#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 * 1000 + 1000;
int a[maxn];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) a[i] = i ^ a[i - 1];
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    ret ^= a[n % i];
    if ((n / i) % 2 == 1) ret ^= a[i - 1];
  }
  while (n--) {
    int x;
    cin >> x;
    ret ^= x;
  }
  cout << ret << endl;
}

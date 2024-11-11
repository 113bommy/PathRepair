#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, a[N], b[N];
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  int pos = n, cnt = 0;
  cout << 1 << ' ';
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[a[i]] = 1;
    while (b[pos]) pos--, cnt++;
    cout << i - cnt + 1 << ' ';
  }
  return 0;
}

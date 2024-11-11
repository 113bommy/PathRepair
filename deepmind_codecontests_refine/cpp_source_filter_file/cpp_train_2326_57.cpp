#include <bits/stdc++.h>
using namespace std;
void TxtRead() {
  freopen("cut.in", "r", stdin);
  freopen("cut.out", "w", stdout);
}
const int N = 1e3 + 5;
int d, n;
int a[N];
int cnt;
int main() {
  iostream::sync_with_stdio(false);
  cin >> d >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n - 1; i++) {
    cnt += d - a[i];
  }
  cout << cnt;
}

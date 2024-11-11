#include <bits/stdc++.h>
using namespace std;
int d[105];
int main(int argc, char **argv) {
  ios::sync_with_stdio(0);
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> d[i];
  }
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i < b - 1; i++) {
    ans += d[i];
  }
  cout << ans;
  return 0;
}

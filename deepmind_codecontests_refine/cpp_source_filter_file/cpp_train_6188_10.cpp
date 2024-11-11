#include <bits/stdc++.h>
using namespace std;
int di[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dj[] = {1, -1, 0, 0, 1, -1, 1, -1};
int ans[101];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b, x;
  cin >> n >> a >> b;
  while (n--) {
    cin >> x;
    cout << ((x * a) % b) / a << " \n"[n == 0];
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int ans;
int main() {
  int n;
  cin >> n;
  int sequence[100005];
  ans = -1000010;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    sequence[x] = sequence[x - 1] + 1;
    ans = max(ans, sequence[x]);
  }
  cout << n - ans << endl;
  return 0;
}

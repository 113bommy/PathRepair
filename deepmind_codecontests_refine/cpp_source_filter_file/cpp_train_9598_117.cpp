#include <bits/stdc++.h>
using namespace std;
void task() {
  int n, a, b, ans;
  cin >> n >> a >> b;
  int pos = n - a;
  if (pos > b)
    ans = n - b;
  else
    ans = a + 1;
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  task();
  return 0;
}

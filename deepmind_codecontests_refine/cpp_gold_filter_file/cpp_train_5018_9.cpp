#include <bits/stdc++.h>
using namespace std;
int a, b;
int Solve(int k) {
  int ans = (max(a, b) - min(a, b)) / k;
  int s = (max(a, b) - min(a, b)) % k;
  if (s == 0)
    return ans;
  else if (s <= 2)
    return ans + 1;
  else
    return ans + 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    cin >> a >> b;
    cout << min(Solve(1), min(Solve(2), Solve(5))) << '\n';
  }
}

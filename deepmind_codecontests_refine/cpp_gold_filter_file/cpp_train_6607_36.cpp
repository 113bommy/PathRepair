#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (int i = 2; i <= n; i++) cout << i << " ";
  if (n >= 1) cout << 1;
  return 0;
}

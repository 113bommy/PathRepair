#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b;
  cin >> a >> b;
  set<int> s;
  int ans = 0;
  for (int i = 1; i <= 63; i++) {
    long long int x = (1LL << i) - 1;
    for (int j = 1; j < i; j++) {
      long long int y = (1LL << j);
      long long int z = (x - y);
      if (z >= a && z <= b) {
        ans++;
      }
    }
  }
  cout << ans << ("\n");
}

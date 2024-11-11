#include <bits/stdc++.h>
using namespace std;
int v[100010];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  int i = 0;
  while (k - (i + 1) > 0) {
    k -= i + 1;
    i++;
  }
  cout << v[k];
  return 0;
}

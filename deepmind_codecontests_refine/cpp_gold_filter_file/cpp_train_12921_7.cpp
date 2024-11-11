#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, k = 0;
  scanf("%d", &n);
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    mp[x] = i;
  }
  while (n--) {
    int cnt = 0;
    scanf("%d", &x);
    if (mp[x] > k) {
      cnt = mp[x] - k;
      k = mp[x];
    }
    cout << cnt << " ";
  }
}

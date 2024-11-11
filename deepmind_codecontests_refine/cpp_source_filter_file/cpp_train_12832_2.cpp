#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N];
bool cmp(int a, int b) { return a > b; }
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    map<int, int> mp;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      int x;
      scanf("%d", &x);
      mp[x]++;
    }
    int ans = 0, maxx = 0;
    int n1 = n * 2;
    while (n1 >= 2) {
      ans = 0;
      for (int i = 1; i <= n1 / 2; i++) {
        if (i == n1 / 2 && n1 % 2 == 0)
          ans += mp[n1] / 2;
        else if (mp[i] != 0 && mp[n1 - i] != 0 && n1 - i >= 1)
          ans += min(mp[i], mp[n1 - i]);
      }
      n1--;
      maxx = max(ans, maxx);
    }
    printf("%d\n", maxx);
  }
  return 0;
}

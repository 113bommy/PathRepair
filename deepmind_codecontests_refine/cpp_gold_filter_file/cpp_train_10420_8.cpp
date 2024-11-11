#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int a[200001];
  map<int, int> mp;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    if (mp[a[i]]) return puts("0"), 0;
    mp[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    if (mp[a[i] & x]) {
      if (a[i] == (a[i] & x)) {
        if (mp[a[i]] >= 2) return puts("1"), 0;
      } else
        return puts("1"), 0;
    }
  }
  map<int, int> ma;
  for (int i = 1; i <= n; i++) {
    if (ma[a[i] & x]) return puts("2"), 0;
    ma[a[i] & x]++;
  }
  puts("-1");
}

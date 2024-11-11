#include <bits/stdc++.h>
using namespace std;
map<char, int> l;
map<char, int> r;
int n, k;
int a[1000005];
int main() {
  cin >> n >> k;
  char temp;
  memset(a, 0, sizeof(a));
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    if (l[temp] == 0) {
      l[temp] = i;
    }
    r[temp] = max(r[temp], i);
  }
  for (auto const& il : l) a[il.second]++;
  for (auto const& ir : r) a[ir.second]--;
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    cur += a[i];
    if (cur > k) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}

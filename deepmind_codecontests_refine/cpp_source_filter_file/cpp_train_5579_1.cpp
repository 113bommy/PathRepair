#include <bits/stdc++.h>
using namespace std;
long long int Abs(long long int a) {
  if (a >= 0) return a;
  return -a;
}
int main() {
  long long int n, m, k, v, i, flag, j, l;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> k;
    map<long long int, int> mp;
    flag = 0;
    for (j = 0; j < k; j++) {
      cin >> v;
      mp[v]++;
      v = -v;
      if (mp[v] == 1) flag = 1;
    }
    if (flag == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}

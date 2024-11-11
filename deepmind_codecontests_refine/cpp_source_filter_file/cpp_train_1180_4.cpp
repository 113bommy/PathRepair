#include <bits/stdc++.h>
using namespace std;
long i, j, n, k, a, ans;
vector<long> v;
map<long, long> m;
int main() {
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }
  i = j = 0;
  while (i < n) {
    m[v[i]]++;
    while (m[v[i]] >= k) {
      ans += n - i;
      m[v[j]]--;
      j++;
    }
    i++;
  }
  cout << ans;
  return 0;
}

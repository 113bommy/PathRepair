#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long y, k, n;
  cin >> y >> k >> n;
  set<long long> s;
  for (int i = k; i <= n; i += k)
    if (i > y) s.insert(i - y);
  long long a = s.size();
  if (a)
    for (int i : s) cout << i << ' ';
  else
    cout << "-1\n";
  return 0;
}

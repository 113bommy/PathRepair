#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long int n, m;
  cin >> n >> m;
  vector<long long int> v;
  long long int ex = 0;
  long long int sum = 0;
  for (long long int a = 0; a < n; a++) {
    long long int st, end;
    cin >> st >> end;
    ex = ex + end;
    sum = sum + st;
    v.push_back(st - end);
  }
  if (ex > m) {
    cout << -1;
  } else if (sum <= m) {
    cout << 0;
  } else {
    sort(v.begin(), v.end());
    long long int ans = 0;
    long long int need = sum - m;
    long long int fa = 0;
    for (long long int b = v.size() - 1; b >= 0; b--) {
      fa++;
      ans = ans + v[b];
      if (ans >= need) {
        cout << fa;
        break;
      }
    }
  }
  return 0;
}

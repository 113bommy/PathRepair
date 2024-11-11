#include <bits/stdc++.h>
using namespace std;
long long t, n, nr0, sum, ans, v[100005];
bool ok;
vector<int> a;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (long long bit = 32; bit >= 0; bit--) {
    int cnt = 0, first;
    for (int i = 1; i <= n; i++)
      if (((1 << bit) & v[i])) {
        cnt++;
        first = v[i];
      }
    if (cnt == 1) {
      cout << first << " ";
      for (int i = 1; i <= n; i++)
        if (v[i] != first) cout << v[i] << " ";
      ok = 1;
      break;
    }
  }
  if (!ok)
    for (int i = 1; i <= n; i++) cout << v[i] << " ";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < (int)n; i++) cin >> v[i];
  int res = 0;
  for (int i = 0; i < (int)n; i++) {
    int tem = v[i];
    for (long long j = i + 1; j < (long long)n; j++) {
      tem ^= v[j];
      res = max(res, tem);
    }
    res = max(res, tem);
  }
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long ans;
vector<long long> v;
int main() {
  ios_base::sync_with_stdio(0);
  for (int i = 0; i < 3; i++) {
    int q;
    cin >> q;
    v.push_back(q);
  }
  ans = v[0] + v[1] + v[2] - 1;
  for (int i = 0; i < 3; i++)
    for (int j = i + 1; j < 3; j++) {
      if ((v[i] - v[j]) % 2 == 0) ans = min(ans, max(v[i], v[j]));
    }
  cout << ans << endl;
  return 0;
}

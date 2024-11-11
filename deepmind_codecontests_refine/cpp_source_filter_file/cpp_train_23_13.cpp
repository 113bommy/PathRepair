#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  set<int> v, v0, v1;
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    if (a == 0 && b == 0) continue;
    if (a == 0 && b == 1) {
      v1.insert(t);
    }
    if (a == 1 && b == 0) v0.insert(t);
    if (a == 1 && b == 1) v.insert(t);
  }
  int c = 0;
  int ans = 0;
  while (c < k) {
    if (v0.size() == 0 && v.size() == 0) {
      cout << "-1";
      return 0;
    }
    if (v1.size() == 0 && v.size() == 0) {
      cout << "-1";
      return 0;
    }
    if (v1.size() == 0) {
      ans += *(v.begin());
      v.erase(v.begin());
      c++;
      continue;
    }
    if (v0.size() == 0) {
      ans += *(v.begin());
      v.erase(v.begin());
      c++;
      continue;
    }
    if (v.size() == 0) {
      ans += *(v1.begin()) + *(v0.begin());
      v1.erase(v1.begin());
      v0.erase(v0.begin());
      c++;
      continue;
    }
    if (*(v.begin()) < *(v1.begin()) + *(v0.begin())) {
      ans += *(v.begin());
      v.erase(v.begin());
      c++;
    } else {
      ans += *(v1.begin()) + *(v0.begin());
      v1.erase(v1.begin());
      v0.erase(v0.begin());
      c++;
    }
  }
  cout << ans << endl;
}

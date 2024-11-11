#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool f(string v1, string v2) {
  string v3 = v2;
  int t = v1.size();
  for (int i = 0; t + i <= v2.size(); ++i) {
    sort(v2.begin() + i, v2.begin() + i + t);
    int x = i;
    int u = 0;
    for (; u < t;) {
      if (v1[u] == v2[x]) {
        ++u;
        ++x;
        continue;
      } else
        goto T;
    }
    return true;
  T:
    v2 = v3;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  int i = 0;
  string v1, v2;
  while (i <= n) {
    ++i;
    cin >> v1 >> v2;
    sort(v1.begin(), v1.end());
    if (f(v1, v2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int cn[100] = {};
  short v[100001];
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
    (cn + 20)[v[i]]++;
  }
  int s = 0, p = 1;
  for (int i = 1; i <= n; i++) {
    if (v[i] < 0) s += (cn + 20)[-v[i]];
    if (!v[i]) {
      s += (cn + 20)[0] - p;
      p++;
    }
  }
  cout << s;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, v[200001] = {0}, i, minn = 1000000001;
  char s[200001];
  bool ok = false;
  cin >> n;
  cin.get();
  cin.getline(s, 200001);
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (i = 0; i < n - 1; i++) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      if (minn > (v[i + 1] - v[i]) / 2) {
        minn = (v[i + 1] - v[i]) / 2;
        ok = true;
      }
    }
  }
  if (ok == true)
    cout << minn;
  else
    cout << -1;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, h, m;
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> h >> m;
    v[i] = 60 * h + m;
  }
  if (v[0] >= 1 + s) {
    cout << 0 << " " << 0;
    return 0;
  } else {
    for (int i = 1; i < n; i++) {
      if ((v[i] - v[i - 1]) >= 2 * s + 2) {
        cout << (v[i - 1] + s + 1) / 60 << " " << (v[i - 1] + 1 + s) % 60;
        return 0;
      }
    }
  }
  cout << (v[n - 1] + 1 + s) / 60 << " " << (v[n - 1] + 1 + s) % 60;
  return 0;
}

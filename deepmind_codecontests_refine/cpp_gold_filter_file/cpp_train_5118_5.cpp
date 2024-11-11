#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int m, n;
  cin >> m >> n;
  vector<bitset<10000>> a(m);
  for (int i = 0; i < m; i++) {
    a[i].reset();
    int s;
    cin >> s;
    while (s--) {
      int x;
      cin >> x;
      a[i].set(x - 1);
    }
  }
  bool flag = true;
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      if ((a[i] & a[j]).none()) {
        flag = false;
      }
    }
  }
  if (flag) {
    cout << "possible";
  } else {
    cout << "impossible";
  }
  return 0;
}

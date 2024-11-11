#include <bits/stdc++.h>
using namespace std;
void solve() {
  int a, b;
  cin >> a >> b;
  vector<int> v;
  v.push_back(b);
  while (a < b) {
    int d = a % b;
    if (d % 2 == 1 && d != 1) {
      break;
    }
    if (b % 10 == 1) {
      b = b / 10;
    } else {
      b = b / 2;
    }
    v.push_back(b);
  }
  if (a == b) {
    cout << "YES"
         << "\n";
    cout << v.size() << "\n";
    for (int i = v.size() - 1; i >= 0; i--) {
      cout << v[i] << " ";
    }
  } else {
    cout << "NO";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}

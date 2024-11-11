#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  vector<int> v;
  int x;
  cin >> x;
  while (x--) {
    int c;
    cin >> c;
    int cc = c * 4;
    while (cc--) {
      int b;
      cin >> b;
      v.push_back(b);
    }
    sort(v.begin(), v.end());
    bool yazan = true;
    int r = (v[0] * v[v.size() - 1]) * (v[1] * v[v.size() - 2]);
    for (int i = 0; i < v.size() - 3; i += 4) {
      if ((v[i] * v[v.size() - 1 - i]) * (v[i + 1] * v[v.size() - 2 - i]) !=
              r &&
          v[0] == v[1] && v[v.size() - 1 - i] == v[v.size() - 2 - i]) {
        yazan = false;
        break;
      }
    }
    if (yazan)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    v.clear();
  }
  return 0;
}

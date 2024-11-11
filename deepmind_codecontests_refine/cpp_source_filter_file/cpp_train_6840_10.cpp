#include <bits/stdc++.h>
using namespace std;
map<int, int> M;
int main() {
  int n, k;
  while (cin >> n >> k) {
    M.clear();
    int x, c = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (M.count(x) == 0) c++;
      M[x] = i + 1;
    }
    if (c >= k) {
      cout << "YES\n";
      map<int, int>::iterator it;
      it = M.begin();
      while (c--) {
        cout << (*it).second << " ";
        it++;
      }
      cout << "\n";
    } else
      cout << "NO\n";
  }
  return 0;
}

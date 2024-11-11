#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    int tot = 0;
    vector<int> v;
    for (int i = 1; i < n + 1; i++) {
      if (tot + i > n) {
        v.back() += n - tot;
        break;
      } else {
        tot += i;
        v.push_back(i);
      }
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}

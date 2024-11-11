#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    if (n <= 3) {
      cout << "NO" << endl;
      return 0;
    } else {
      for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
          if (min(v[i], v[i + 1]) < min(v[j], v[j + 1]) and
              max(v[i], v[i + 1]) > min(v[j], v[j + 1]) and
              max(v[i], v[i + 1]) < max(v[j], v[j + 1])) {
            cout << "yes" << endl;
            return 0;
          }
          if (max(v[i], v[i + 1]) > max(v[j], v[j + 1]) and
              min(v[i], v[i + 1]) < max(v[j], v[j + 1]) and
              min(v[j], v[j + 1]) < min(v[i], v[i + 1])) {
            cout << "yes" << endl;
            return 0;
          }
        }
      }
      cout << "no" << endl;
    }
  }
  return 0;
}

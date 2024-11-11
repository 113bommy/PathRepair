#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  int sol = 0;
  for (int i = 0; i < n; i += 2) {
    if (v[i] != v[i + 1]) {
      int p = 0;
      for (int j = i + 1; j < 2 * n; ++j) {
        if (v[i] == v[j]) {
          p = j;
          break;
        }
      }
      sol += abs(i - p) - 1;
      for (int j = p; j > i; --j) {
        swap(v[j], v[j - 1]);
      }
    }
  }
  cout << sol << endl;
  return 0;
}

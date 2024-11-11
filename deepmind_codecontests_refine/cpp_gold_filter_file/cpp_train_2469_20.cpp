#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a;
  cin >> n;
  vector<int> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    m.push_back(a);
  }
  sort(m.begin(), m.end());
  for (int i = 0; i < n - 1; i++) {
    if (i % 2 == 0) {
      m.pop_back();
    } else {
      m.erase(m.begin());
    }
  }
  cout << m[0];
  return 0;
}

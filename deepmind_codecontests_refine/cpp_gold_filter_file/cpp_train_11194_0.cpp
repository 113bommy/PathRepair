#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int> v[2];
int main() {
  cin >> n >> a >> b;
  if (n > (a * b)) return cout << -1, 0;
  for (int i = 1; i < n + 1; ++i) v[i % 2].push_back(i);
  for (int i = 0; i < a; ++i) {
    for (int j = 1; j < b + 1; ++j) {
      if (v[(i + j) % 2].size() == 0) {
        cout << 0 << ' ';
        continue;
      }
      cout << v[(i + j) % 2].back() << " ";
      v[(i + j) % 2].pop_back();
    }
    cout << endl;
  }
}

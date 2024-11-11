#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int inf = (int)1e9;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  vector<int> s;
  int z;
  for (int i = 0; i < n; ++i) {
    cin >> z;
    s.push_back(z);
  }
  sort(s.begin(), s.end());
  int x = s[a];
  int x1 = s[a + 1];
  cout << x1 - x;
  return 0;
}

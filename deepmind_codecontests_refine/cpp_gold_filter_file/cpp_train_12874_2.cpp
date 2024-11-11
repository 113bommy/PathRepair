#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, c = 0;
  cin >> n;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    if (v[i] != v[i + 1] && v[i] != 0) {
      c++;
    }
  }
  cout << c << endl;
}

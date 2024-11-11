#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> v(100);
  int c[1000] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    c[v[i]]++;
  }
  for (int i = 0; i < 1000; i++) {
    if (c[i] > (n + 1) / 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}

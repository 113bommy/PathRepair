#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, s;
  cin >> n >> s;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    v[i] = a * 60 + b;
  }
  if (v[0] >= s + 1) {
    cout << 0 << " " << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    int x = v[i] + s + 1;
    int y = x + s + 1;
    if (y <= v[i + 1]) {
      cout << x / 60 << " " << x % 60 << endl;
      return 0;
    }
  }
  int x = v[n - 1] + s + 1;
  cout << x / 60 << " " << x % 60 << endl;
  return 0;
}

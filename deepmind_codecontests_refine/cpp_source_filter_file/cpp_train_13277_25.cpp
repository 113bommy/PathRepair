#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  int x = b[0];
  for (int i = 1; i < n; i++) {
    if (b[i] >= x + 1) {
      b[i] = x + 1;
      x++;
    }
  }
  cout << x + 1 << endl;
  return 0;
}

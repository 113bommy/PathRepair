#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n, d, i, c = 0, k, j;
  string a, b;
  char ch;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    sort(a.begin(), a.end());
    for (j = 1; j < a.size(); j++) {
      if (a[0] != a[j]) {
        c++;
        break;
      }
    }
    if (c == 1)
      cout << a << endl;
    else
      cout << -1 << endl;
  }
  c = 0;
  return 0;
}

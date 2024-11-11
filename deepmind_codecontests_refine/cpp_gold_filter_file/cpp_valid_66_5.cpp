#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  for (int i = 1; i < 1700; i++) {
    if (i % 3 == 0 || i % 10 == 3)
      continue;
    else
      a.push_back(i);
  }
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << a[n - 1] << endl;
  }
  return 0;
}

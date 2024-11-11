#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    int n, k, x;
    cin >> n >> k;
    vector<int> a;
    int c = 0;
    for (int i = 0; i < n; i++) {
      cin >> x;
      a.push_back(x + k);
      if (x + k < 5) c++;
    }
    cout << c % 3;
  }
  return 0;
}

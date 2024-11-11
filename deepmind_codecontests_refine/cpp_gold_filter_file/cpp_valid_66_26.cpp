#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> a;
  for (int i = 1; i <= 10000; i++) {
    if (i % 10 != 3 && i % 3 != 0) {
      a.push_back(i);
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << a[n - 1] << endl;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
      int in;
      cin >> in;
      a.push_back(in);
    }
    int cnt = 0, min = a[n - 1];
    for (int i = n - 1; i > 0; --i) {
      if (a[i - 1] <= min)
        min = a[i - 1];
      else
        ++cnt;
    }
    cout << cnt << endl;
  }
}

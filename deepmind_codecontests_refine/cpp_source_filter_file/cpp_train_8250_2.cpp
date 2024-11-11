#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << endl;
      continue;
    }
    vector<int> pre1;
    list<int> pre2;
    a += '0';
    b += '0';
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1]) pre1.push_back(i);
      if (b[i] != b[i - 1]) pre2.push_front(i);
    }
    cout << pre1.size() + pre2.size() << ' ';
    for (auto &it : pre1) cout << it << ' ';
    for (auto &it : pre2) cout << it << ' ';
    cout << '\n';
  }
}

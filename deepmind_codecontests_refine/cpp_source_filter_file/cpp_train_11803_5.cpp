#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, p = 0, a = 0;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (a == 2) {
      v.push_back(p);
      a = 0;
      p = 0;
    }
    if (m < 0) {
      a++;
    }
    p++;
  }
  if (p != 0) {
    v.push_back(p);
  }
  cout << v.size() << endl;
  for (auto it : v) {
    cout << it << " ";
  }
  cout << endl;
}

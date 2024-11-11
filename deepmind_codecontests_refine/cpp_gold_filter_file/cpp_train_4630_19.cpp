#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<queue<int> > v(4);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v[a].push(i + 1);
  }
  int mi = (1 << 30);
  for (int i = 1; i <= 3; i++) {
    if (!v[i].size()) {
      cout << 0 << '\n';
      return 0;
    }
    mi = min(mi, (int)v[i].size());
  }
  cout << mi << '\n';
  for (int i = 0; i < mi; i++) {
    for (int i = 1; i <= 3; i++) {
      cout << v[i].front() << ' ';
      v[i].pop();
    }
    cout << '\n';
  }
}

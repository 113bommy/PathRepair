#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> x, y;
  while (n--) {
    int a, b;
    cin >> a >> b;
    x.insert(a);
    y.insert(b);
  }
  cout << max(x.size(), y.size()) << endl;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  set<int> x;
  set<int>::iterator it;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    x.insert(y);
  }
  int num = 0;
  for (it = x.begin(); it != x.end(); it++) {
    int w = *it;
    if (w <= n) {
      num++;
    }
  }
  cout << n - num << endl;
}

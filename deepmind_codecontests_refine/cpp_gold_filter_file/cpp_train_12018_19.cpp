#include <bits/stdc++.h>
using namespace std;
int b[101000];
int main() {
  int n;
  cin >> n;
  bool flag = true;
  for (int i = 0; i < 101000; i++) {
    b[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (b[y] + 1 < x) {
      flag = false;
    }
    b[y] = max(b[y], x);
  }
  if (flag) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
  return 0;
}

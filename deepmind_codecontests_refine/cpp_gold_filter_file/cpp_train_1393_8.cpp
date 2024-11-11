#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, num = 0;
  cin >> n;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    sum += x;
  }
  bool b = 0;
  vector<int> ve;
  for (int i = 1, x = 1; i <= n + n + 1 + 5; i++, x += n + 1) {
    ve.push_back(x);
  }
  for (int i = 1, x; i <= 5; i++) {
    x = sum + i;
    for (int j = 0; j < ve.size(); j++) {
      if (x == ve[j]) {
        b = 1;
        break;
      }
    }
    if (b == 0) num++;
    b = 0;
  }
  cout << num << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int res = 0, cur = a.find(b);
  while (cur < a.size()) {
    ++res;
    cur += b.size();
    cur = a.find(b, cur + 1);
  }
  cout << res << endl;
  return 0;
}

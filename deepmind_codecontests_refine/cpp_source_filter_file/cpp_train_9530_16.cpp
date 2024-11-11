#include <bits/stdc++.h>
using namespace std;
class participant {
 public:
  string name;
  int before;
  int after;
  bool red() {
    if (before >= 2400 && (after - before) > 0)
      return true;
    else
      false;
  }
};
int main() {
  int n;
  cin >> n;
  participant P[n];
  for (int i = 0; i < n; i++) {
    cin >> P[i].name >> P[i].before >> P[i].after;
    if (P[i].red()) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

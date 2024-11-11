#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:133217728")
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> x;
  for (int i = 0; i < n; i++) {
    char p;
    cin >> p;
    if (p == '4') {
      x.push_back(3);
      x.push_back(2);
      x.push_back(2);
    } else if (p == '6') {
      x.push_back(5);
      x.push_back(3);
    } else if (p == '8') {
      x.push_back(7);
      x.push_back(2);
      x.push_back(2);
      x.push_back(2);
    } else if (p == '9') {
      x.push_back(7);
      x.push_back(3);
      x.push_back(3);
      x.push_back(2);
    } else if (p > '1')
      x.push_back(p - '0');
  }
  sort(x.begin(), x.end());
  reverse(x.begin(), x.end());
  for (int i = 0; i < x.size(); i++) cout << x[i];
  return 0;
}

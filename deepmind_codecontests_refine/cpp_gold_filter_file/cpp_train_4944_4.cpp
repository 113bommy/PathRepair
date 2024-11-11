#include <bits/stdc++.h>
using namespace std;
list<int> fd, sd;
int main() {
  int n;
  cin >> n;
  int k1, k2;
  cin >> k1;
  for (int i = 0, a; i < k1; i++) {
    cin >> a;
    fd.push_back(a);
  }
  cin >> k2;
  for (int i = 0, a; i < k2; i++) {
    cin >> a;
    sd.push_back(a);
  }
  int fights = 0;
  while (!fd.empty() && !sd.empty()) {
    int a, b;
    a = fd.front();
    b = sd.front();
    fd.pop_front();
    sd.pop_front();
    if (a > b) {
      fd.push_back(b);
      fd.push_back(a);
    } else {
      sd.push_back(a);
      sd.push_back(b);
    }
    fights++;
    if (fights > 200) {
      cout << -1;
      return 0;
    }
  }
  if (fd.empty())
    cout << fights << " " << 2;
  else
    cout << fights << " " << 1;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p = -1;
  cin >> n;
  string y;
  cin >> y;
  int r = y.size();
  for (int i = 0; i < r; i++) {
    if (y[i] > y[i + 1]) {
      p = i;
      break;
    }
  }
  if (p == -1) {
    p = r - 1;
  } else {
    p = p;
  }
  vector<char> a;
  for (int i = 0; i < r; i++) {
    a.push_back(y[i]);
  }
  a.erase(a.begin() + p);
  for (auto i = a.begin(); i != a.end(); i++) {
    cout << *i;
  }
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  bool rated = false;
  cin >> n;
  vector<int> v;
  vector<int> z;
  int m, k;
  while (n--) {
    cin >> m >> k;
    if (m - k < 0) return cout << "rated" << endl, 0;
    v.push_back(m);
  }
  z = v;
  sort(v.begin(), v.end());
  if (v == z) {
    cout << "maybe" << endl;
  } else {
    cout << "unrated" << endl;
  }
}

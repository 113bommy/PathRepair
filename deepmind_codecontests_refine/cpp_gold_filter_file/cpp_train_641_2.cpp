#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int main() {
  for (int i = 0; i < 4; ++i) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  int x = a[3] + a[0], y = a[1] + a[2];
  if (x != y) {
    int zsm = 0;
    for (int i = 0; i < 3; ++i) {
      zsm += a[i];
    }
    if (a[3] != zsm) {
      cout << "NO";
    } else {
      cout << "YES";
    }
  } else {
    cout << "YES";
  }
  return 0;
}

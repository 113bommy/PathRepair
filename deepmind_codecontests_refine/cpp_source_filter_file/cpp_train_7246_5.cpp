#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }
  bool nafisa = true;
  int kk = abs(v[0] - v[1]);
  for (int i = 0; i < n - 1; i++) {
    int g = abs(v[i] - v[i + 1]);
    if (g != kk) {
      nafisa = false;
      break;
    }
  }
  if (nafisa) {
    cout << v[n - 1] + kk << endl;
  } else {
    cout << v[n - 1] << endl;
  }
  return 0;
}

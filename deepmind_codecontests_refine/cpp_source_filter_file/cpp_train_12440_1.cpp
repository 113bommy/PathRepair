#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    while (a % 2 == 0) a = a / 2;
    while (a % 3 == 0) a = a / 3;
    v.push_back(a);
  }
  for (int i = 0; i < v.size(); i++) {
    if (v[i] != v[i + 1]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}

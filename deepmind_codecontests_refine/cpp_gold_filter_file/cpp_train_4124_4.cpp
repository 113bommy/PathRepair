#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int main() {
  int n;
  cin >> n;
  v.resize(n + 13);
  v[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  v[n + 1] = 10001;
  int num1 = 0, num2 = 0;
  vector<int> zn;
  for (int i = 1; i < n; i++) {
    if (v[i] == v[i + 1]) {
      zn.push_back(1);
    }
    if (v[i] > v[i + 1]) {
      zn.push_back(2);
    }
    if (v[i] < v[i + 1]) {
      zn.push_back(0);
    }
  }
  int cnt = 0;
  for (int i = 1; i < (int)zn.size(); i++) {
    if (zn[i - 1] > zn[i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}

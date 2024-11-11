#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, sum = 0;
  cin >> a;
  vector<int> v;
  for (int i = 0; i < a; i++) {
    int n;
    cin >> n;
    v.push_back(n);
  }
  bool flag = true;
  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    if (v[i] % v[0] != 0) {
      flag = false;
      break;
    }
  }
  if (flag == false) {
    cout << -1 << endl;
  } else
    cout << v[0] << endl;
}

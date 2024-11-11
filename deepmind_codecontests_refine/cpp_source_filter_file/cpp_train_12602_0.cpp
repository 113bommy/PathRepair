#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> vn(n);
  for (int i = 0; i < n; i++) {
    cin >> vn.at(i);
  }
  int m;
  cin >> m;
  vector<int> vm(m);
  for (int i = 0; i < m; i++) {
    cin >> vm.at(i);
  }
  if (vn > vm) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
}

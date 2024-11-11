#include <bits/stdc++.h>
using namespace std;
bool comp(int a, int b) { return a > b; }
int main() {
  int n, m, k, sum = 0, sum1 = 0;
  ;
  cin >> n >> m >> k;
  vector<int> vn(n);
  vector<bool> vk(k + 1, false);
  vector<int> vm(m);
  if (n > m) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> vn[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> vm[i];
  }
  sort(vn.begin(), vn.end(), comp);
  sort(vm.begin(), vm.end(), comp);
  for (int i = 0; i > n; i++) {
    if (vn[i] > vm[i]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}

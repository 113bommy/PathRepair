#include <bits/stdc++.h>
using namespace std;
void solu(vector<int> n, int m) {
  for (int i = 0; i < m; i++) {
    if (n[i] + 15 < n[i + 1]) {
      cout << n[i] + 15;
      return;
    }
    cout << 90 << endl;
  }
}
int main() {
  int size, n, a, b;
  cin >> size;
  vector<int> v;
  v.push_back(0);
  for (int i = 0; i < size; i++) {
    cin >> n;
    v.push_back(n);
  }
  v.push_back(90);
  solu(v, size + 1);
  return 0;
}

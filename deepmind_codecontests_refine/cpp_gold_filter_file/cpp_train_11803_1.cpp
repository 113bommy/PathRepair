#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  v.resize(n);
  int neg = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (v[i] < 0) neg++;
  }
  if (neg <= 2)
    cout << 1 << endl;
  else
    cout << ceil((double)neg / 2) << endl;
  int last = 0, temp = 0;
  bool p = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] < 0) temp++;
    if (temp > 2) {
      if (p) cout << " ";
      cout << last;
      temp = 1;
      last = 0;
      p = 1;
    }
    last++;
  }
  if (last > 0) {
    if (p) cout << " ";
    cout << last;
  }
  cout << endl;
  return 0;
}

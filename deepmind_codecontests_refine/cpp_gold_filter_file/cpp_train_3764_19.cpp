#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a;
  for (int i = 0; i < 4; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(), a.end());
  cout << a[3] - a[0] << " " << a[3] - a[2] << " " << a[3] - a[1] << endl;
  return 0;
}

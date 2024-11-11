#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(4);
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < 3; i++) {
    cout << a[3] - a[i] << " ";
  }
  return 0;
}

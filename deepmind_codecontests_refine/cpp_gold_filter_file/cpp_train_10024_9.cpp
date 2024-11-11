#include <bits/stdc++.h>
using namespace std;
int a[105];
int main() {
  int n, c = 0;
  pair<int, int> mi, ma;
  mi.first = 999;
  ma.first = -1;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= mi.first) {
      mi.first = a[i];
      mi.second = i;
    }
    if (a[i] > ma.first) {
      ma.first = a[i];
      ma.second = i;
    }
  }
  c = ma.second;
  c += n - mi.second - 1;
  if (mi.second < ma.second) c--;
  cout << c << endl;
  return 0;
}

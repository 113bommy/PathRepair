#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, b;
  cin >> n >> b;
  int a[n], curr = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  std::vector<int> v;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2)
      curr--;
    else
      curr++;
    if (curr == 0 && i + 1 < n) v.push_back(a[i + 1] - a[i]);
  }
  if (v.size()) sort(v.begin(), v.end());
  int cnt = 0, ind = 0;
  while (ind < v.size() && v[ind] <= b) {
    cnt++;
    b -= v[ind];
    ind++;
  }
  cout << cnt << endl;
  return 0;
}

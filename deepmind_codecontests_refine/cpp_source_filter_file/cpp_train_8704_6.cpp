#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, l = 0, n, diff;
  vector<int> v;
  cin >> n;
  while (n != 0) {
    v.push_back(n % 10);
    n = n / 10;
  }
  k = v.size();
  for (i = v.size() - 1; i >= 0; i--) {
    if (v[i] == 0)
      k--;
    else
      break;
  }
  for (i = 0; i < v.size(); i++) {
    if (v[i] == 0)
      l++;
    else
      break;
  }
  for (i = l; i < (k - l) / 2; i++) {
    if (v[i] != v[k - 1 - i]) {
      cout << "NO";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}

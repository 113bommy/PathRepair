#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, tmp, g = 0, l = 0, i = 300, j = -1, r = 0, ii = 300;
  vector<int> num;
  cin >> n;
  while (n--) {
    cin >> tmp;
    num.push_back(tmp);
  }
  for (int k = 0; k < num.size(); k++) {
    if (num[k] == 0) {
      l += 1;
    } else {
      l -= 1;
    }
    if (l < 0) {
      l = 0;
      i = k + 1;
    }
    if (l > g) {
      ii = i;
      g = l;
      j = k;
    }
  }
  for (int k = 0; k < num.size(); k++) {
    if (ii <= k && k <= j) {
      num[k] = 1 - num[k];
    }
    if (num[k] == 1) r++;
  }
  if (g == 0) r--;
  cout << r;
  return 0;
}

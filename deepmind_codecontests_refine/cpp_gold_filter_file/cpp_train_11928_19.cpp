#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int debug = 0;
  if (debug == 1) {
    freopen("input.txt", "r", stdin);
  }
  int n;
  int c, d;
  cin >> n;
  long long lb, ub;
  lb = -1111111111;
  ub = 1111111111;
  vector<int> ca(n);
  vector<int> da(n);
  for (int i = 0; i < n; i++) {
    cin >> ca[i] >> da[i];
  }
  int cu = 0;
  for (int i = 0; i < n; i++) {
    if (da[i] == 2) {
      ub = min(ub, (long long)1899 - cu);
    } else {
      lb = max(lb, (long long)1900 - cu);
    }
    cu += ca[i];
  }
  if (ub < lb) {
    cout << "Impossible" << '\n';
  } else if (ub == 1111111111) {
    cout << "Infinity" << '\n';
  } else {
    cout << ub + cu << '\n';
  }
  return 0;
}

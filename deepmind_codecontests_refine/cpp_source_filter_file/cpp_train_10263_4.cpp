#include <bits/stdc++.h>
using namespace std;
bool findI(vector<int> &stewards, int &n, int &j, int &val) {
  for (int i = 0; i < j; i++) {
    if (stewards[i] < val) {
      return true;
    }
  }
  return false;
}
bool findJ(vector<int> &stewards, int &n, int &j, int &val) {
  for (int i = n; i > j; i--) {
    if (stewards[i] > val) {
      return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, r = 0;
  cin >> n;
  if (n <= 2) {
    cout << 0;
    return 0;
  }
  vector<int> stewards(n);
  for (int i = 0; i < n; ++i) {
    cin >> stewards[i];
  }
  sort(stewards.begin(), stewards.end());
  for (int j = 1; j < n - 1; ++j) {
    if (findI(stewards, n, j, stewards[j]) &&
        findJ(stewards, n, j, stewards[j])) {
      r++;
    }
  }
  cout << r;
  return 0;
}

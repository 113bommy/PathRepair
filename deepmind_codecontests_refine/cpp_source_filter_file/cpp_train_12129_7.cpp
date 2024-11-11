#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> bj(n);
  vector<vector<int> > aij(2);
  for (int i = 0; i < 2; i++) {
    for (int i = 0; i < n - 1; i++) {
      int t;
      cin >> t;
      aij[i].push_back(t);
    }
  }
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    bj[i] = t;
  }
  int result = 1000000000;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      int s = 0;
      for (int k = i; k < n - 1; k++) {
        s += aij[1][k];
      }
      s += bj[i];
      for (int k = 0; k < i; k++) {
        s += aij[0][k];
      }
      for (int k = 0; k < j; k++) {
        s += aij[0][k];
      }
      s += bj[j];
      for (int k = j; k < n - 1; k++) {
        s += aij[1][k];
      }
      result = min(result, s);
    }
  }
  cout << result << endl;
  return 0;
}

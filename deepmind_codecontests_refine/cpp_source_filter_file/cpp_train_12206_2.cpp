#include <bits/stdc++.h>
using namespace std;
int a[1000 * 1000];
int main() {
  int t;
  cin >> t;
  long long s = 0;
  for (int i = 0; i < t; i++) {
    cin >> a[i];
    s += a[i];
  }
  vector<int> ind;
  for (int i = 0; i < t; i++) {
    double p = ((s - a[i]) / (t - 1));
    if (a[i] == p) ind.push_back(i + 1);
  }
  cout << ind.size() << endl;
  for (int i = 0; i < ind.size(); i++) {
    cout << ind[i] << " ";
  }
  return 0;
}

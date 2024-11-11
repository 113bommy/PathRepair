#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k, t, n, m, v;
  cin >> n >> v;
  int count = 0;
  vector<int> vec;
  int minm, ind, temp;
  for (i = 0; i < n; i++) {
    cin >> ind;
    minm = 1000002;
    for (j = 0; j < ind; j++) {
      cin >> temp;
      minm = min(temp, minm);
    }
    if (v > minm) {
      vec.push_back(ind);
      count++;
    }
  }
  cout << count << endl;
  for (i = 0; i < vec.size(); i++) cout << vec[i] << " ";
  return 0;
}

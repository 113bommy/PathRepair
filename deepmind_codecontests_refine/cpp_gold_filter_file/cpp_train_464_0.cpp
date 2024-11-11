#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > v;
int main() {
  int i, j, k, n, c = 0;
  cin >> n >> k;
  for (i = 0; i < k; i++) {
    int temp;
    cin >> temp;
    vector<int> v1;
    for (j = 0; j < temp; j++) {
      int t;
      cin >> t;
      v1.push_back(t);
    }
    if (v1.size() > 1) {
      vector<int> v2;
      v2.push_back(v1[0]);
      int ii;
      for (ii = 0; ii < v1.size() - 1;) {
        if (v1[ii] == v1[ii + 1] - 1) {
          v2.push_back(v1[ii + 1]);
          ii++;
        } else {
          c++;
          v.push_back(v2);
          v2.clear();
          c += v1.size() - ii - 2;
          for (int kk = ii + 1; kk < v1.size(); kk++) {
            v2.clear();
            v2.push_back(v1[kk]);
            v.push_back(v2);
            v2.clear();
          }
          break;
        }
      }
      if (v2.size() > 0) v.push_back(v2);
    } else
      v.push_back(v1);
  }
  sort(v.begin(), v.end());
  int sum = c;
  for (i = 0; i < v.size() - 1; i++) {
    if (v[i + 1].size() > 1) {
      int temp = v[i + 1].size() - 1;
      sum += temp;
      sum++;
      sum += temp;
    } else
      sum++;
  }
  cout << sum << "\n";
  return 0;
}

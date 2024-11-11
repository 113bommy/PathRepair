#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int I = 11;
pair<int, int> a[5000];
int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a, a + n);
  int m1 = 1, m2 = 1;
  vector<vector<int>> v;
  for (int i = 0; i < n;) {
    int j = i;
    vector<int> t;
    while (j < n && a[j].first == a[i].first) t.push_back(a[j++].second);
    v.push_back(t);
    i = j;
  }
  int m = 0;
  for (int i = 0; i < v.size(); i++)
    for (int j = i + 1; j < v.size(); j++) {
      int k = 1;
      if (v[i][0] < v[j][0]) {
        int jj = 0, ii = 0;
        while (ii < v[i].size() && jj < v[j].size()) {
          while (jj < v[j].size() && v[j][jj] < v[i][ii]) jj++;
          if (jj < v[j].size()) {
            k++;
            while (ii < v[i].size() && v[i][ii] < v[j][jj]) ii++;
            if (ii < v[i].size()) k++;
          }
        }
      } else {
        int jj = 0, ii = 0;
        while (ii < v[i].size() && jj < v[j].size()) {
          while (ii < v[i].size() && v[i][ii] < v[j][jj]) ii++;
          if (ii < v[i].size()) {
            k++;
            while (jj < v[j].size() && v[j][jj] < v[i][ii]) jj++;
            if (jj < v[j].size()) k++;
          }
        }
      }
      if (k > m) m = k;
    }
  cout << m;
  return 0;
}

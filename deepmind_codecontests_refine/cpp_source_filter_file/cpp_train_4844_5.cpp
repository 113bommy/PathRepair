#include <bits/stdc++.h>
using namespace std;
int n, i, j, k;
int main() {
  scanf("%d", &n);
  ;
  vector<int> a, b;
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    ;
    if (j) a.push_back(j);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    ;
    if (j) b.push_back(j);
    if (a[0] == j) k = b.size() - 1;
  }
  vector<int> x;
  for (i = 0; i < a.size(); i++, k++) {
    if (k == a.size()) k = 0;
    x.push_back(b[k]);
  }
  for (i = 0; i < n; i++) {
    if (a[i] != x[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}

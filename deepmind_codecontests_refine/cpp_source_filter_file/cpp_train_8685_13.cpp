#include <bits/stdc++.h>
using namespace std;
int n;
int m;
vector<int> gen(int num) {
  if (num == 1) {
    vector<int> vv;
    vv.push_back(1);
    return vv;
  }
  if (num == 2) {
    vector<int> vv;
    vv.push_back(1);
    vv.push_back(8);
    return vv;
  }
  vector<int> ret;
  ret.push_back(num - 2);
  for (int i = 1; i < num; i++) {
    ret.push_back(2);
  }
  return ret;
}
vector<int> t;
vector<int> y;
int main() {
  cin >> n >> m;
  t = gen(n);
  y = gen(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (j) printf(" ");
      printf("%d", t[i] * y[j]);
    }
    puts("");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<string> v;
int main() {
  int n;
  int i = 0, j = 0, k = 0;
  ;
  string str;
  cin >> n;
  vector<vector<int> > v_r(n + 10);
  vector<vector<int> > v_c(n + 10);
  vector<string> v1;
  for ((i) = (0); (i) < (n); (i++)) {
    cin >> str;
    for ((j) = (0); (j) < (n); (j++)) {
      if (str[j] == '.') v_r[i].push_back(j);
    }
    v1.push_back(str);
  }
  for ((i) = (0); (i) < (n); (i++)) {
    for ((j) = (0); (j) < (n); (j++)) {
      if (v1[j][i] == '.') v_c[i].push_back(i);
    }
  }
  bool flag = true;
  for ((i) = (0); (i) < (n); (i++)) {
    if (v_r[i].size() == 0) flag = false;
  }
  if (flag == true) {
    for ((i) = (0); (i) < (n); (i++))
      cout << (i + 1) << " " << (v_r[i][0] + 1) << endl;
    return 0;
  }
  flag = true;
  for ((i) = (0); (i) < (n); (i++)) {
    if (v_r[i].size() == 0) flag = false;
  }
  if (flag == true) {
    for ((i) = (0); (i) < (n); (i++))
      cout << (v_c[i][0] + 1) << " " << (i + 1) << endl;
    return 0;
  }
  cout << (-1) << endl;
}

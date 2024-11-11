#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<string> vs;
int r, c;
int f() {
  for (int i = 0; i < m; i++) {
    int leftOdd = 0, leftEven = 0, rightOdd = 0, rightEven = 0;
    bool found = false;
    for (int j = 0; j < n; j++) {
      if (isdigit(vs[i][j])) {
        found = true;
        if (j % 2) {
          if (vs[i][j] == '1' || vs[i][j] == '2')
            leftOdd++;
          else
            rightOdd++;
        } else {
          if (vs[i][j] == '1' || vs[i][j] == '2')
            leftEven++;
          else
            rightEven++;
        }
      }
    }
    if (found) r++;
    if (leftOdd && rightOdd || leftEven && rightEven || leftOdd && leftEven ||
        rightEven && rightOdd)
      return 0;
  }
  for (int i = 0; i < n; i++) {
    int upOdd = 0, upEven = 0, downOdd = 0, downEven = 0;
    bool found = false;
    for (int j = 0; j < m; j++) {
      if (isdigit(vs[j][i])) {
        found = true;
        if (j % 2) {
          if (vs[j][i] == '1' || vs[j][i] == '4')
            upOdd++;
          else
            downOdd++;
        } else {
          if (vs[j][i] == '1' || vs[j][i] == '4')
            upEven++;
          else
            upEven++;
        }
      }
    }
    if (found) c++;
    if (upOdd && downOdd || upEven && downEven || upOdd && upEven ||
        downOdd && downEven)
      return 0;
  }
  int p = m + n - r - c;
  int ret = 1;
  for (int i = 0; i < p; i++) ret = (ret * 2) % 1000003;
  return ret;
}
int main() {
  cout << setprecision(9);
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    vs.push_back(s);
  }
  int ret = f();
  cout << ret << endl;
  return 0;
}

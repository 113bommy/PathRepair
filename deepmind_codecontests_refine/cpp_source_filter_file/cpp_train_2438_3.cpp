#include <bits/stdc++.h>
using namespace std;
struct sort_vec_size {
  bool operator()(const vector<int> &left, const vector<int> &right) {
    return left.size() < right.size();
  }
};
inline int readInt() {
  register int c = getchar();
  int x = 0;
  for (; (c < 48 || c > 57); c = getchar())
    ;
  for (; c > 47 && c < 58; c = getchar()) {
    x = x * 10 + c - 48;
  }
  return x;
}
int main() {
  int n = readInt();
  vector<vector<int> > nums;
  for (int i = 0; i < int(n); i++) {
    int m = readInt();
    vector<int> num;
    for (int j = 0; j < int(m); j++) {
      num.push_back(readInt());
    }
    sort(num.begin(), num.end());
    nums.push_back(num);
  }
  bool mat[n][n];
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(n); j++) mat[i][j] = false;
  }
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(n); j++) {
      if (nums[i].size() < nums[j].size())
        mat[i][j] = true;
      else {
        int cur = 0;
        for (int k = 0; k < int(nums[i].size()); k++) {
          if (cur == nums[j].size()) break;
          if (nums[i][k] == nums[j][cur]) {
            cur++;
          } else if (nums[i][k] < nums[j][cur]) {
            mat[i][j] = true;
            break;
          } else {
          }
        }
        if (cur < nums[j].size()) mat[i][j] = true;
      }
    }
  }
  for (int i = 0; i < int(n); i++) {
    bool flag = true;
    for (int j = 0; j < int(n); j++) {
      if (i != j) flag = flag && mat[i][j];
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

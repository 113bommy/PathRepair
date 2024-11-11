#include <bits/stdc++.h>
using namespace std;
vector<int> grp[100002];
int main() {
  int n, k, i, j, a[100002], flag = 0;
  scanf("%d%d", &n, &k);
  ;
  for (i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s[0] == '?')
      a[i] = INT_MIN;
    else {
      int sign = 1, l = s.size();
      a[i] = 0, j = 0;
      if (s[0] == '-') {
        sign = -1;
        j = 1;
      }
      for (; j < l; j++) a[i] = a[i] * 10 + (s[j] - '0');
      a[i] *= sign;
    }
    grp[i % k].push_back(a[i]);
  }
  for (i = 0; i < k; i++) {
    int l = grp[i].size(), val, cur = INT_MIN, pos = 0, prev = -1;
    if (l == 0) {
      if (grp[i][0] == INT_MIN) grp[i][0] = 0;
      continue;
    }
    while (pos < l) {
      if (grp[i][pos] != INT_MIN) {
        int ele = pos - prev - 1, cnt;
        if (cur >= 0)
          cnt = cur + 1;
        else if (grp[i][pos] < 0)
          cnt = grp[i][pos] - ele;
        else
          cnt = min(max(0 - ele / 2, cur + 1), grp[i][pos] - ele);
        for (j = prev + 1; j < pos; j++) grp[i][j] = cnt++;
        cur = grp[i][pos];
        prev = pos;
      }
      pos++;
    }
    int ele = l - 1 - prev, cnt = max(cur + 1, 0 - ele / 2);
    for (j = prev + 1; j < l; j++) grp[i][j] = cnt++;
    for (j = 0; j < l - 1; j++)
      if (grp[i][j] >= grp[i][j + 1]) flag = 1;
  }
  if (flag)
    cout << "Incorrect sequence\n";
  else {
    int cnt = 0, j = 0;
    while (cnt < n) {
      printf("%d ", grp[cnt % k][j]);
      cnt++;
      if (cnt % k == 0) j++;
    }
    cout << endl;
  }
  return 0;
}

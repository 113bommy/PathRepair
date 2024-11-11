#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
int main() {
  string s;
  int n;
  while (~scanf("%d", &n)) {
    cin >> s;
    int len = s.size();
    vector<int> vec;
    int a[1000], idx = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '*') {
        vec.push_back(i + 1);
        a[idx++] = i + 1;
      }
    }
    bool flag = 0;
    for (int i = 0; i < vec.size(); i++) {
      int t = vec[i];
      for (int j = 1; j <= 25; j++) {
        bool ans = 0;
        for (int k = 0; k <= 4; k++) {
          if (vec[i] + k * j <= len && s[vec[i] + k * j - 1] != '*')
            ans = 1;
          else if (vec[i] + k * j > len)
            ans = 1;
        }
        if (ans == 0) {
          flag = 1;
          break;
        }
      }
      if (flag) break;
    }
    if (flag)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 10;
vector<string> tot[MaxN];
map<string, int> c;
int cnt;
char s[MaxN];
bool check[MaxN], flag;
set<string> ans;
int main() {
  scanf("%s", s);
  int len = strlen(s);
  check[len] = 1;
  for (int i = len - 2; i >= 5; i--) {
    if (check[i + 2]) {
      string t;
      t += s[i];
      t += s[i + 1];
      if (tot[i + 2].size() == 0) {
        check[i] = 1;
        tot[i].push_back(t);
        ans.insert(t);
      } else {
        flag = 0;
        for (int j = 0; j < tot[i + 2].size(); j++) {
          if (tot[i + 2][j] == t) {
            flag = 1;
            break;
          }
        }
        if (!flag) {
          tot[i].push_back(t);
          ans.insert(t), check[i] = 1;
        }
      }
    }
    if (check[i + 3]) {
      string t;
      t += s[i];
      t += s[i + 1];
      t += s[i + 2];
      if (tot[i + 3].size() == 0) {
        check[i] = 1;
        tot[i].push_back(t);
        ans.insert(t);
      } else {
        flag = 0;
        for (int j = 0; j < tot[i + 2].size(); j++) {
          if (tot[i + 3][j] == t) {
            flag = 1;
            break;
          }
        }
        if (!flag) {
          tot[i].push_back(t);
          ans.insert(t), check[i] = 1;
        }
      }
    }
  }
  printf("%d\n", ans.size());
  for (auto &ite : ans) {
    cout << ite << endl;
  }
  return 0;
}

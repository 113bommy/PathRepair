#include <bits/stdc++.h>
using namespace std;
int a;
int b;
int c;
int lang;
vector<int> vec[102];
vector<int> user[102];
int flag[102] = {0};
int num = 0;
int literate = 0;
void dfs(int emp) {
  if (!flag[emp]) {
    flag[emp] = 1;
    for (int i = 0; i < user[emp].size(); i++) {
      for (int j = 0; j < vec[user[emp][i]].size(); j++) {
        if (!flag[vec[user[emp][i]][j]]) dfs(vec[user[emp][i]][j]);
      }
    }
  }
}
int main() {
  scanf("%d %d", &a, &b);
  for (int i = 1; i <= a; i++) {
    scanf("%d", &c);
    if (c > 0) literate++;
    for (int j = 0; j < c; j++) {
      scanf("%d", &lang);
      vec[lang].push_back(i);
      user[i].push_back(lang);
    }
  }
  for (int i = 1; i <= b; i++) {
    if (!flag[i]) {
      dfs(i);
      num++;
    }
  }
  if (literate) num--;
  printf("%d\n", num);
  return 0;
}

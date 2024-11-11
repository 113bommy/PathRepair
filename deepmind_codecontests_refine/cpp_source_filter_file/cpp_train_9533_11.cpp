#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const short d[8][2] = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
struct Node {
  string s;
  int sub, dep;
} node[MAX >> 5];
char s[MAX];
int n;
void Get_String() {
  int i = 0, l = strlen(s);
  n = 0;
  while (i < l) {
    while (s[i] != ',') {
      node[n].s += s[i];
      i++;
    }
    i++;
    node[n].sub = 0;
    while (s[i] && s[i] != ',') {
      node[n].sub = node[n].sub * 10 + s[i] - '0';
      i++;
    }
    node[n].dep = -1;
    n++;
    i++;
  }
}
void Fun(int& i, int depth) {
  node[i].dep = depth;
  int num = node[i].sub;
  i++;
  while (num) {
    node[i].dep = depth;
    Fun(i, depth + 1);
    num--;
  }
}
void Solve() {
  for (int i = 0; i < n; i++) {
    if (node[i].dep == -1) {
      Fun(i, 0);
      i--;
    }
  }
}
vector<int> v[MAX];
void Print() {
  int root = 0;
  for (int i = 0; i < n; i++) {
    v[node[i].dep].push_back(i);
    if (node[i].dep > root) root = node[i].dep;
  }
  printf("%d\n", root);
  for (int i = 0; i < MAX; i++) {
    int l = v[i].size();
    for (int j = 0; j < l; j++) {
      cout << node[v[i][j]].s;
      if (j == l - 1)
        printf("\n");
      else
        printf(" ");
    }
  }
}
int main() {
  while (~scanf("%s", s)) {
    Get_String();
    Solve();
    Print();
    for (int i = 0; i < MAX; i++) v[i].clear();
  }
  return 0;
}

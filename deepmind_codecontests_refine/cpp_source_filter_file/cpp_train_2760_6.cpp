#include <bits/stdc++.h>
using namespace std;
char a[1010][1010], b[1010][1010];
int n, m;
int c = 1;
int c_elem[1000010], comp[1001][1001] = {0}, v[1000010] = {0};
void dfs(int row, int col, int component) {
  if ((row == 0) || (col == 0) || (row == n + 1) || (col == m + 1) ||
      (comp[row][col] != 0) || (a[row][col] == '*')) {
    return;
  }
  comp[row][col] = component;
  c_elem[component]++;
  dfs(row, col - 1, component);
  dfs(row, col + 1, component);
  dfs(row - 1, col, component);
  dfs(row + 1, col, component);
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    char temp[1001];
    scanf("%s", temp);
    for (int j = 1; j <= m; j++) {
      a[i][j] = temp[j - 1];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == '.' && !comp[i][j]) {
        dfs(i, j, c);
        c++;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == '*') {
        int cnt = 1;
        set<int> st;
        st.insert(comp[i - 1][j]);
        st.insert(comp[i + 1][j]);
        st.insert(comp[i][j - 1]);
        st.insert(comp[i][j + 1]);
        for (set<int>::iterator it = st.begin(); it != st.end(); it++)
          cnt += c_elem[*it];
        b[i][j - 1] = (cnt % 10) + '0';
      } else {
        b[i][j - 1] = '.';
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%s\n", b[i]);
  }
  return 0;
}

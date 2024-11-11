#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j = 0, k, l = 0;
  cin >> n;
  char a[n][101];
  for (i = 0; i < n; i++) scanf("%s", &a[i][0]);
  vector<char> v[26], t;
  int indeg[26] = {0}, visited[26] = {0};
  for (i = 1; i < n; i++) {
    while (a[i][j] || a[i - 1][j]) {
      if (!a[i][j]) {
        cout << "Impossible";
        return 0;
      } else if (a[i - 1][j]) {
        if (a[i][j] == a[i - 1][j])
          j++;
        else {
          v[a[i - 1][j] - 97].push_back(a[i][j]);
          indeg[a[i][j] - 97]++;
          break;
        }
      } else
        break;
    }
    j = 0;
  }
  while (l < 26) {
    for (k = 0; k < 26; k++) {
      if ((indeg[k] == 0) && (visited[k] == 0)) {
        t.push_back(k + 97);
        for (auto e : v[k]) indeg[e - 97]--;
        visited[k] = 1;
      }
    }
    l++;
  }
  if (t.size() == 26)
    for (auto e : t) cout << e;
  else
    cout << "Impossible";
  return 0;
}

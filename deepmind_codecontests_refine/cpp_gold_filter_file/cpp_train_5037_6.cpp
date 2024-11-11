#include <bits/stdc++.h>
using namespace std;
string s[100005];
int lps[3 * 100005];
vector<int> child[100005];
string pat;
void LPS() {
  lps[0] = 0;
  int i = 0, j = 1;
  while (j < (int)pat.size()) {
    if (pat[i] == pat[j]) {
      lps[j] = i + 1;
      i++, j++;
    } else {
      if (i == 0) {
        lps[j] = 0;
        j++;
      } else
        i = lps[i - 1];
    }
  }
  for (int i = 1; i < (int)pat.size(); i++) {
    while (lps[i - 1] != 0 && pat[i] == pat[lps[i - 1]])
      lps[i - 1] = lps[lps[i - 1] - 1];
  }
}
int cnt = 0;
void dfs(int node, int jj) {
  int temp = jj;
  for (auto other : child[node]) {
    jj = temp;
    for (int i = 0; i < (int)s[other].size(); i++) {
      if (s[other][i] == pat[jj]) {
        jj++;
        if (jj == (int)pat.size()) {
          jj = lps[jj - 1];
          cnt++;
        }
      } else {
        if (jj != 0) {
          jj = lps[jj - 1];
          i--;
        }
      }
    }
    dfs(other, jj);
  }
}
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int p;
  for (int i = 2; i <= n; i++) {
    cin >> p >> s[i];
    child[p].push_back(i);
  }
  cin >> pat;
  LPS();
  s[1] = "";
  dfs(1, 0);
  cout << cnt << endl;
  return 0;
}

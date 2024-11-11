#include <bits/stdc++.h>
using namespace std;
int n;
char a[100005];
char b[100005];
int cnt = 0;
bool visited[26] = {0};
vector<char> p;
vector<int> graph[26];
void dfs(int v) {
  visited[v] = 1;
  cnt++;
  for (int k : graph[v]) {
    if (!visited[k]) {
      char a, b;
      a = 'a' + v;
      b = 'a' + k;
      p.push_back(a);
      p.push_back(b);
      dfs(k);
    }
  }
}
int main() {
  int i, j, t;
  cin >> n;
  scanf("%s", a);
  scanf("%s", b);
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      graph[a[i] - 'a'].push_back(b[i] - 'a');
      graph[b[i] - 'a'].push_back(a[i] - 'a');
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    cnt = 0;
    if (!visited[i]) {
      dfs(i);
      ans += (cnt - 1);
    }
  }
  printf("%d\n", ans);
  for (int i = 0; i < p.size(); i += 2) {
    printf("%c %c\n", p[i], p[i + 1]);
  }
  return 0;
}

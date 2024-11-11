#include <bits/stdc++.h>
using namespace std;
int n, arr[102] = {0};
string s[102];
list<int> q;
vector<int> v;
void bfs() {
  int u, i;
  while (!q.empty()) {
    u = q.front();
    q.pop_front();
    for (i = 0; i < n; i++) {
      if (s[u][i] == '1') {
        if (arr[i] == 0) continue;
        arr[i]--;
        if (arr[i] == 0) {
          q.push_back(i);
          v.push_back(i);
        }
      }
    }
  }
}
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] == 0) {
      q.push_back(i);
      v.push_back(i);
    }
  }
  printf("%d\n", v.size());
  for (auto &t : v) {
    printf("%d ", t + 1);
  }
  return 0;
}

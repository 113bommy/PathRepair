#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int cur);
queue<int> q;
vector<int> an[200005];
bool book[200005];
int _max, timea[200005], timeb[200005];
int main() {
  int n, x, reco;
  scanf("%d%d", &n, &x);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    an[a].push_back(b);
    an[b].push_back(a);
  }
  reco = 1;
  timea[1] = 0;
  book[1] = true;
  q.push(reco);
  while (!q.empty()) {
    int Q;
    Q = q.front();
    for (int i = 0; i < an[Q].size(); i++) {
      if (book[an[Q][i]] == false) {
        book[an[Q][i]] = true;
        reco = an[Q][i];
        timea[an[Q][i]] = timea[Q] + 1;
        q.push(reco);
      }
    }
    q.pop();
  }
  memset(book, false, sizeof(book));
  reco = x;
  timeb[1] = 0;
  book[x] = true;
  q.push(reco);
  while (!q.empty()) {
    int Q;
    Q = q.front();
    for (int i = 0; i < an[Q].size(); i++) {
      if (book[an[Q][i]] == false) {
        book[an[Q][i]] = true;
        reco = an[Q][i];
        timeb[an[Q][i]] = timeb[Q] + 1;
        q.push(reco);
      }
    }
    q.pop();
  }
  _max = -1;
  for (int i = 2; i <= n; i++) {
    if (timeb[i] <= timea[i]) {
      if (timea[i] > _max) _max = timea[i];
    }
  }
  printf("%d", 2 * _max);
  return 0;
}

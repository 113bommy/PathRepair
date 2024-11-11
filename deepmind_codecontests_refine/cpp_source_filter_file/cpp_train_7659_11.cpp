#include <bits/stdc++.h>
using namespace std;
int cost[100010];
int n;
vector<int> edge[100010];
int st;
int par[100010];
void go(int i) {
  for (int j = 0; j < edge[i].size(); j++) {
    int gj = edge[i][j];
    if (gj == par[i]) continue;
    par[gj] = i;
    go(gj);
  }
}
void read() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", cost + i);
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  scanf("%d", &st);
  st--;
}
void init() {
  par[st] = -1;
  go(st);
}
long long total[100010];
long long save[100010];
void calculate(int i) {
  int myValue = cost[i];
  if (i != st) myValue = cost[i] - 1;
  int leftSave = 0;
  vector<int> temp;
  for (int j = 0; j < edge[i].size(); j++) {
    int gj = edge[i][j];
    if (gj == par[i]) continue;
    calculate(gj);
    leftSave += save[gj];
    temp.push_back(1 + total[gj]);
  }
  sort(temp.begin(), temp.end());
  total[i] = 0;
  for (int j = temp.size() - 1; j >= 0 && myValue > 0; j--, myValue--) {
    total[i] += temp[j] + 1;
  }
  total[i] += 2 * min(myValue, leftSave);
  if (myValue > leftSave) save[i] = myValue - leftSave;
}
int main() {
  read();
  init();
  calculate(st);
  cout << total[st] << endl;
  return 0;
}

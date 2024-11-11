#include <bits/stdc++.h>
using namespace std;
bool mark[300000];
vector<int> arr[300000];
vector<int> pasos;
int n;
bool t = false;
void bfs(int ini) {
  if (ini == n) {
    cout << "1 ";
    for (int i = 0; i < pasos.size(); i++) {
      cout << pasos[i] << " ";
    }
    cout << endl;
    t = true;
    return;
  }
  if (mark[ini] || t) return;
  for (int i = 0; i < arr[ini].size(); i++) {
    if (!mark[arr[ini][i]]) {
      mark[ini] = true;
      pasos.push_back(arr[ini][i]);
      bfs(arr[ini][i]);
      mark[ini] = false;
      pasos.pop_back();
    }
  }
}
int main() {
  scanf("%d", &n);
  int a;
  for (int i = 2; i <= n; i++) {
    scanf("%d", &a);
    arr[i].push_back(a);
    arr[a].push_back(i);
  }
  bfs(1);
  return 0;
}

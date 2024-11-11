#include <bits/stdc++.h>
using namespace std;
int n, m;
bool graph[100][100];
bool traversed[100];
void search(int x) {
  for (int i = 0; i <= m; i++)
    if (graph[x][i])
      for (int k = 0; k < n; k++)
        if (graph[k][i] && !traversed[k]) {
          traversed[k] = true;
          search(k);
        }
}
int main() {
  cin >> n >> m;
  int size, lang;
  int need = 0;
  int all = 0;
  for (int i = 0; i < n; i++) {
    cin >> size;
    if (size == 0) all++;
    for (int k = 0; k < size; k++) {
      cin >> lang;
      graph[i][lang] = true;
    }
  }
  if (all == n)
    cout << all << endl;
  else {
    for (int i = 0; i < n; i++) {
      if (!traversed[i]) {
        need++;
        traversed[i] = true;
        search(i);
      }
    }
    cout << need - 1 << endl;
  }
  return 0;
}

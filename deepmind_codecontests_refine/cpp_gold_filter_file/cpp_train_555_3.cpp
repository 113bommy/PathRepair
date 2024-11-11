#include <bits/stdc++.h>
using namespace std;
int n;
bool graph[110][110];
int main() {
  cin >> n;
  memset(graph, 0, sizeof(graph));
  int current = 0;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < i; j++) {
      if (!graph[j][i]) {
        int counter = 0;
        for (int k = 0; k < i; k++) {
          if (graph[j][k] && graph[k][i]) counter++;
        }
        if (current + counter <= n) {
          current += counter;
          graph[j][i] = graph[i][j] = true;
        }
      }
    }
  }
  cout << 100 << endl;
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) cout << graph[i][j];
    cout << endl;
  }
  return 0;
}

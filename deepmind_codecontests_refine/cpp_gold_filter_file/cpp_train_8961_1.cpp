#include <bits/stdc++.h>
using namespace std;
bool search(int s[], int n, int t) {
  for (int i = 0; i < n; i++) {
    if (s[i] == t) return true;
  }
  return false;
}
int main() {
  int n;
  cin >> n;
  n++;
  int d[n];
  d[0] = 0;
  for (int i = 1; i < n; i++) cin >> d[i];
  int visited[n];
  int visitIndex, target;
  for (int i = 1; i < n; i++) {
    visitIndex = 0;
    visited[visitIndex++] = i;
    target = d[i];
    while (true) {
      if (search(visited, visitIndex, target)) {
        cout << target << " ";
        break;
      }
      visited[visitIndex++] = target;
      target = d[target];
    }
  }
  cout << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> adjL(N, -1);
  for (int n = 0; n < N; n++) {
    cin >> adjL[n];
    adjL[n]--;
  }
  bool c = false;
  for (int i = 0; i < N; i++) {
    int node = i;
    for (int x = 0; x < 4; x++) {
      if (adjL[node] != -1) {
        node = adjL[node];
      }
    }
    if (node == 1) {
      cout << "YES";
      c = true;
      break;
    }
  }
  if (!c) cout << "NO";
  return 0;
}

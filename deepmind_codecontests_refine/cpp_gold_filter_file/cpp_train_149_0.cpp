#include <bits/stdc++.h>
using namespace std;
int n, m;
int w[500];
int b[1000];
bool seen[500];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> w[i];
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i]--;
  }
  int total = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) seen[j] = false;
    for (int j = i + 1; (j < m) && (b[j] != b[i]); j++) {
      if (seen[b[j]]) continue;
      seen[b[j]] = true;
      total += w[b[i]];
    }
  }
  cout << total << endl;
}

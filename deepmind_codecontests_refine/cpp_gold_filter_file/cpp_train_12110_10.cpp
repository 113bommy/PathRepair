#include <bits/stdc++.h>
using namespace std;
int results[101][101];
bool successful[101];
int main() {
  int n;
  int m;
  cin >> n >> m;
  memset(results, 0, sizeof(results));
  memset(successful, 0, sizeof(successful));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      results[i][j] = s[j] - '0';
    }
  }
  int maxdegree[101];
  memset(maxdegree, 0, sizeof(maxdegree));
  for (int i = 0; i < m; i++) {
    int max = results[0][i];
    for (int j = 1; j < n; j++) {
      if (results[j][i] > max) max = results[j][i];
    }
    maxdegree[i] = max;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (results[i][j] == maxdegree[j]) {
        count++;
        break;
      }
    }
  }
  cout << count << endl;
  return 0;
}

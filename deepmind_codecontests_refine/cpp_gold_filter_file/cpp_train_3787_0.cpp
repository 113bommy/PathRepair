#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  vector<char> line;
  char bg;
  unsigned int n, t, j;
  cin >> n >> t;
  for (unsigned int i = 0; i < n; i++) {
    cin >> bg;
    line.push_back(bg);
  }
  for (unsigned int i = 0; i < t; i++) {
    j = 0;
    while (j < n - 1) {
      if (line[j] == 'B' && line[j + 1] == 'G') {
        line[j] = 'G';
        line[j + 1] = 'B';
        j++;
      }
      j++;
    }
  }
  for (unsigned int i = 0; i < n; i++) cout << line[i];
  return 0;
}

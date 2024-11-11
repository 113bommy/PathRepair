#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string words[m][2], lec[n];
  for (int i = 0; i < m; i++) {
    cin >> words[i][0] >> words[i][1];
  }
  for (int i = 0; i < n; i++) {
    cin >> lec[i];
  }
  for (int i = 0; i < n; i++) {
    if (i < (n - 1)) {
      for (int j = 0; j < m; j++) {
        if (lec[i] == words[j][0] || lec[i] == words[j][1]) {
          if (words[j][0].length() > words[j][1].length()) {
            cout << words[j][1] << " ";
          } else {
            cout << words[j][0] << " ";
          }
        }
      }
    } else {
      for (int j = 0; j < m; j++) {
        if (lec[i] == words[j][0] || lec[i] == words[j][1]) {
          if (words[j][0].length() > words[j][1].length()) {
            cout << words[j][1] << " ";
          } else {
            cout << words[j][0];
          }
        }
      }
    }
  }
  return 0;
}

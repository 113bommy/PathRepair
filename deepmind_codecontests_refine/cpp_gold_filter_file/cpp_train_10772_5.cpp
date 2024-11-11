#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0;
  string s1, s2;
  cin >> n >> s1 >> s2;
  vector<int> arr[26][26];
  for (int i = 0; i < n; i++) {
    arr[s1[i] - 'a'][s2[i] - 'a'].push_back(i);
  }
  int ret = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i != j) {
        if (arr[i][j].size() > 0 && arr[j][i].size() > 0) {
          swap(s1[arr[i][j][0]], s1[arr[j][i][0]]);
          for (int x = 0; x < (int)s1.size(); x++) {
            if (s1[x] != s2[x]) ret++;
          }
          cout << ret << endl;
          cout << arr[i][j][0] + 1 << " " << arr[j][i][0] + 1;
          return 0;
        }
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i != j) {
        for (int k = 0; k < 26; k++) {
          if (j != k) {
            if (arr[i][j].size() > 0 && arr[j][k].size() > 0) {
              swap(s1[arr[i][j][0]], s1[arr[j][k][0]]);
              for (int x = 0; x < (int)s1.size(); x++) {
                if (s1[x] != s2[x]) ret++;
              }
              cout << ret << endl;
              cout << arr[i][j][0] + 1 << " " << arr[j][k][0] + 1;
              return 0;
            }
          }
        }
      }
    }
  }
  for (int x = 0; x < (int)s1.size(); x++) {
    if (s1[x] != s2[x]) ret++;
  }
  cout << ret << endl << -1 << " " << -1;
  return 0;
}

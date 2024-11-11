#include <bits/stdc++.h>
using namespace std;
void p(vector<vector<char>> &v) {
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      cout << v[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
int main() {
  int k;
  cin >> k;
  if (k == 1) {
    cout << -1 << endl;
    return 0;
  }
  vector<vector<char>> v(k, vector<char>(k, '0')), v1(k, vector<char>(k, '0'));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      v[i][j] = 'b';
      v1[i][j] = 'w';
    }
  }
  for (int i = 0; i < k; i += 2) {
    for (int j = i; j < k - i; j++) {
      v[i][j] = 'w';
      v[k - i - 1][j] = 'w';
      v[j][i] = 'w';
      v[j][k - i - 1] = 'w';
      v1[i][j] = 'b';
      v1[k - i - 1][j] = 'b';
      v1[j][i] = 'b';
      v1[j][k - i - 1] = 'b';
    }
  }
  for (int i = 0; i < k; i++) {
    if (i % 2 == 0)
      p(v);
    else
      p(v1);
  }
  return 0;
}

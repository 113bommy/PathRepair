#include <bits/stdc++.h>
using namespace std;
int ulo[24][6] = {{1, 2, 3, 4, 5, 6}, {4, 1, 2, 3, 5, 6}, {3, 4, 1, 2, 5, 6},
                  {2, 3, 4, 1, 5, 6}, {3, 2, 1, 4, 6, 5}, {4, 3, 2, 1, 6, 5},
                  {1, 4, 3, 2, 6, 5}, {2, 1, 4, 3, 6, 5}, {6, 2, 5, 4, 1, 3},
                  {4, 6, 2, 5, 1, 3}, {5, 4, 6, 2, 1, 3}, {2, 5, 4, 6, 1, 3},
                  {5, 2, 6, 4, 3, 1}, {4, 5, 2, 6, 3, 1}, {6, 4, 5, 2, 3, 1},
                  {2, 6, 4, 5, 3, 1}, {1, 6, 3, 5, 2, 4}, {5, 1, 6, 3, 2, 4},
                  {3, 5, 1, 6, 2, 4}, {6, 3, 5, 1, 2, 4}, {3, 6, 1, 5, 4, 2},
                  {5, 3, 6, 1, 4, 2}, {1, 5, 3, 6, 4, 2}, {6, 1, 5, 3, 4, 2}};
bool equal(vector<int>& a, vector<int>& b, string& cols) {
  bool res = false;
  for (int i = 0; i < 24; i++) {
    bool flag = true;
    for (int j = 0; j < 6; j++) {
      if (cols[a[j]] != cols[b[ulo[i][j] - 1]]) {
        flag = false;
        break;
      }
    }
    if (flag) {
      res = true;
      break;
    }
  }
  return res;
}
int main() {
  string cols;
  cin >> cols;
  vector<int> a(6);
  for (int i = 0; i < 6; i++) a[i] = i + 1;
  vector<int> cs[100000];
  int cnt = 0;
  while (true) {
    bool fl = true;
    for (int i = 0; i < cnt; i++)
      if (equal(a, cs[i], cols)) {
        fl = false;
        break;
      }
    if (fl) cs[cnt++] = a;
    if (!next_permutation(a.begin(), a.end())) break;
  }
  cout << cnt << endl;
}

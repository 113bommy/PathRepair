#include <bits/stdc++.h>
using namespace std;
int n, m, k;
bool debug = false;
char mp[10][10];
int a[6][6];
vector<string> ans;
void ff(int x, int &ii, int &jj) {
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++)
      if (a[i][j] == x) {
        ii = i;
        jj = j;
        return;
      }
}
void sp(int i, int j) {
  i++;
  j++;
  for (int k = 0; k < 3; k++) {
    ans.push_back("U" + to_string(j));
    ans.push_back("L" + to_string(i));
    ans.push_back("U" + to_string(j));
    ans.push_back("R" + to_string(i));
  }
  ans.push_back("U" + to_string(j));
}
void spH(int i, int j) {
  i++;
  j++;
  for (int k = 0; k < 3; k++) {
    ans.push_back("R" + to_string(i));
    ans.push_back("U" + to_string(j));
    ans.push_back("R" + to_string(i));
    ans.push_back("D" + to_string(j));
  }
  ans.push_back("R" + to_string(i));
}
int main() {
  for (int i = 0; i < 6; i++) scanf("%s", mp[i]);
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) {
      char c = mp[i][j];
      if (c <= '9') {
        a[i][j] = c - '0';
      } else {
        a[i][j] = (c - 'A') + 10;
      }
    }
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 6; j++) {
      int right = i * 6 + j;
      ff(right, n, m);
      while (m != j) {
        int mm = (m + 5) % 6;
        swap(a[n][m], a[n][mm]);
        sp(n, mm);
        m = mm;
      }
      while (n != i) {
        int nn = (n - 1 + 6) % 6;
        swap(a[n][m], a[nn][m]);
        spH(nn, m);
        n = nn;
      }
    }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%s\n", &ans[i][0]);
  return 0;
}

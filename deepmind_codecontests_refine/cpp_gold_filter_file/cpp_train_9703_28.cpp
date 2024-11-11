#include <bits/stdc++.h>
using namespace std;
int n;
void calc() {}
int ls[1000][1000];
int main(int argc, char *argv[]) {
  cin >> n;
  memset(ls, 0, sizeof(ls));
  int o = ((int)sqrt(1 + 8 * n) - 1) / 2;
  cout << o + 1 << endl;
  int k = 0;
  for (int i = o; i >= 1; i--) {
    if (o - i > 0) k = ls[o - i - 1][o - 1];
    for (int j = 1; j <= i; j++) ls[o - i][o - i + j - 1] = k + j;
    if (o - i > 0) k = ls[o][o - i - 1];
    for (int j = 1; j <= i; j++) ls[o - i + j][o - i] = k + j;
  }
  for (int i = 0; i < o + 1; i++) {
    for (int j = 0; j < o; j++) cout << ls[i][j] << " ";
    cout << endl;
  }
  return 0;
}

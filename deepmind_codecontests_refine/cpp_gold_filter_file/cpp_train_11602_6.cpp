#include <bits/stdc++.h>
using namespace std;
int maximum(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
bool cmp(const pair<int, int>& firs, const pair<int, int>& sec) {
  return firs.first < sec.first;
}
string in[100005];
char mark[100005];
int lag[100005];
int main() {
  int n;
  int l, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    cin >> in[i];
  }
  l = in[0].size();
  for (i = 0; i < l; i++) {
    mark[i] = in[0][i];
  }
  int j;
  for (i = 1; i < n; i++) {
    for (j = 0; j < l; j++) {
      if (mark[j] == in[i][j]) {
        continue;
      } else {
        if (mark[j] == '?' && lag[j] == 0) {
          mark[j] = in[i][j];
        } else if (in[i][j] == '?')
          continue;
        else if (mark[j] != '?' && in[i][j] != '?') {
          mark[j] = '?';
          lag[j] = 1;
        }
      }
    }
  }
  for (i = 0; i < l; i++) {
    if (lag[i] == 1)
      printf("%c", mark[i]);
    else {
      if (mark[i] == '?')
        printf("a");
      else
        printf("%c", mark[i]);
    }
  }
  return 0;
}

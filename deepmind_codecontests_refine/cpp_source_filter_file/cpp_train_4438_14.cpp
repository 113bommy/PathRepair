#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> M;
set<pair<int, int> > tmp;
char s[77777][11];
int main() {
  int n;
  scanf("%d", &n);
  for (int ii = 0; ii < n; ii++) {
    scanf("%s", s[ii]);
    for (int i = 0; i < 9; i++) {
      for (int j = i; j < 9; j++) {
        int ans = 0;
        for (int k = i; k <= j; k++) ans = ans * 10 + s[ii][k] - '0';
        tmp.insert(make_pair(j - i + 1, ans));
      }
    }
    for (set<pair<int, int> >::iterator it = tmp.begin(); it != tmp.end();
         it++) {
      M[*it]++;
    }
    tmp.clear();
  }
  for (int ii = 0; ii < n; ii++) {
    int di, dj, res = 9;
    for (int i = 0; i < 9; i++) {
      for (int j = i; j < 9; j++) {
        int ans = 0;
        for (int k = i; k <= j; k++) ans = ans * 10 + s[ii][k] - '0';
        if (M[make_pair(j - i + 1, ans)] == 1 && res > j - i + 1) {
          res = j - i + 1;
          di = i, dj = j;
        }
      }
    }
    for (int k = di; k <= dj; k++) putchar(s[ii][k]);
    puts("");
  }
}

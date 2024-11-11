#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1000 + 5;
int n;
string s;
bool mark[Maxn][Maxn];
void ok(int l1, int l2, int n1, int n2) {
  for (int i = l1; i <= l2; i++)
    for (int j = n1; j <= n2; j++) mark[i][j] = mark[j][i] = true;
  return;
}
int main() {
  cin >> s;
  n = (int)s.size();
  int lastv = 2, last = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '0') {
      for (int j = 0; j < i; j++) {
        mark[lastv][last] = mark[last][lastv] = true;
        last = lastv;
        lastv++;
      }
      ok(last, last, lastv, lastv + (s[i] - '0') - 1);
      int l1 = lastv, l2 = lastv + (s[i] - '0') - 1, n1 = lastv + (s[i] - '0'),
          n2 = lastv + (s[i] - '0') + 9;
      for (int j = i; j < n - 1; j++) {
        ok(l1, l2, n1, n2);
        l1 = n1, l2 = n2;
        n1 = l2 + 1, n2 = l2 + 10;
      }
      ok(l1, l2, 1, 1);
      lastv = l2 + 1;
      last = 0;
    }
  }
  cout << lastv << endl;
  for (int i = 0; i < lastv; i++) {
    for (int j = 0; j < lastv; j++) {
      if (mark[i][j])
        printf("Y");
      else
        printf("N");
    }
    printf("\n");
  }
  return 0;
}

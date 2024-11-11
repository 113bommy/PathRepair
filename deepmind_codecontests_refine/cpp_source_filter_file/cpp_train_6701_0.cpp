#include <bits/stdc++.h>
using namespace std;
int Q[100], n;
string goal = "", P = "", PP = "";
char ret1[100], ret2[100];
inline string go(string s) {
  for (int x = 0; x < n; x++) ret1[x] = s[Q[x]];
  return ret1;
}
inline string goo(string s) {
  for (int x = 0; x < n; x++) ret2[Q[x]] = s[x];
  return ret2;
}
int main() {
  int k, x, y;
  scanf("%d", &n);
  ;
  scanf("%d", &k);
  ;
  for (int x = 0; x < n; x++) {
    scanf("%d", &Q[x]);
    ;
    Q[x]--;
  }
  for (int x = 1; x <= n; x++) P.push_back(x);
  for (int x = 1; x <= n; x++) {
    int p;
    scanf("%d", &p);
    ;
    goal.push_back(p);
  }
  PP = P;
  for (x = 0; x <= k and P != goal; x++, P = go(P))
    ;
  for (y = 0; y <= k and PP != goal; y++, PP = goo(PP))
    ;
  if ((k - x) % 2 && (k - y) % 2 || x == 0 || (k > 1 && x == 1 && y == 1))
    puts("NO");
  else
    puts("YES");
}

#include <bits/stdc++.h>
using namespace std;
int n;
string s, t;
int cnts[30], cntt[30];
int main() {
  scanf("%d", &n);
  cin >> s;
  cin >> t;
  if (s == t) {
    printf("0\n");
    return 0;
  }
  for (int i = 0; i < n; i++) cnts[s[i] - 'a']++;
  for (int i = 0; i < n; i++) cntt[t[i] - 'a']++;
  for (int i = 0; i < 30; i++)
    if (cnts[i] != cntt[i]) {
      printf("-1\n");
      return 0;
    }
  string aux = s, nw;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    int nxt = (n + 1) / 2;
    if (i & 1)
      nxt += i / 2;
    else
      nxt -= i / 2;
    int pos;
    for (int j = n - 1; j >= 0; j--)
      if (aux[j] == t[nxt]) {
        pos = j;
        break;
      }
    ans.push_back(n - pos);
    nw = "";
    for (int j = n - 1; j >= pos; j--) nw += aux[j];
    for (int j = 0; j < pos; j++) nw += aux[j];
    aux = nw;
    ans.push_back(n - (n - pos - 1) - i);
    pos = (n - pos - 1) + i;
    nw = "";
    for (int j = n - 1; j >= pos; j--) nw += aux[j];
    for (int j = 0; j < pos; j++) nw += aux[j];
    aux = nw;
    ans.push_back(n);
    reverse(aux.begin(), aux.end());
  }
  if (aux != t) {
    ans.push_back(n);
    reverse(aux.begin(), aux.end());
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    if (i) printf(" ");
    printf("%d", ans[i]);
  }
  printf("\n");
  return 0;
}

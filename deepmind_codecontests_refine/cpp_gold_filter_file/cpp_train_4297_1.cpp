#include <bits/stdc++.h>
using namespace std;
vector<int> room;
string str[4];
int check(char x) {
  if (x == 'a' || x == 'e' || x == 'i' || x == 'u' || x == 'o') return 1;
  return 0;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int ret = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> str[j];
      string tmp = "";
      bool f = 0;
      for (int k = ((str[j]).size()) - 1, s = 0; k >= 0; k--) {
        tmp += str[j][k];
        if (check(str[j][k])) s++;
        if (s != m) continue;
        str[j] = tmp;
        f = 1;
        break;
      }
      if (f == 0) ret = -1;
    }
    int a = 0, b = 0;
    for (int k = 1; k < 4; k++)
      if (str[k] != str[0]) {
        if (a == 0)
          a = k;
        else if (b == 0)
          b = k;
        else
          ret = -1;
      }
    if (a == 0 && b == 0) continue;
    if (a && b == 0) ret = -1;
    if (str[a] != str[b]) ret = -1;
    if (ret == 0)
      ret = (1 << a) | (1 << b);
    else if (ret != ((1 << a) | (1 << b)))
      ret = -1;
  }
  if (ret == -1)
    cout << "NO";
  else
    for (int i = 0; i < 4; i++)
      if (ret & (1 << i))
        cout << "b";
      else
        cout << "a";
  cout << endl;
  return 0;
}

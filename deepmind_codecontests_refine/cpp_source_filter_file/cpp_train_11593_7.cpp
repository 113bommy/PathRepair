#include <bits/stdc++.h>
using namespace std;
struct point {
  string name;
  int mi, wi, sc, n;
} a[10];
bool big(int o, int t) {
  if (a[o].sc > a[t].sc) return true;
  if (a[o].sc < a[t].sc) return false;
  if (a[o].mi > a[t].mi) return true;
  if (a[o].mi < a[t].mi) return false;
  if (a[o].wi > a[t].wi) return true;
  if (a[o].wi < a[t].wi) return false;
  if (a[o].name < a[t].name) return true;
  return false;
}
int main() {
  int m = 0;
  for (int i = 0; i < 5; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    int o1 = 0, o2 = 0;
    char c;
    scanf("%c", &c);
    if (c == ' ') scanf("%c", &c);
    while (c != ':') {
      o1 = o1 * 10 + c - 48;
      scanf("%c", &c);
    }
    scanf("%c", &c);
    while (c != '\r' && c != '\n') {
      o2 = o2 * 10 + c - 48;
      scanf("%c", &c);
    }
    int n1 = -1, n2 = -1;
    for (int j = 0; j < m; j++) {
      if (a[j].name == s1) n1 = j;
      if (a[j].name == s2) n2 = j;
    }
    if (n1 == -1) {
      n1 = m++;
      a[n1].name = s1;
      a[n1].sc = 0;
      a[n1].mi = 0;
      a[n1].wi = 0;
      a[n1].n = 0;
    }
    if (n2 == -1) {
      n2 = m++;
      a[n2].name = s2;
      a[n2].sc = 0;
      a[n2].mi = 0;
      a[n2].wi = 0;
      a[n2].n = 0;
    }
    a[n1].n++;
    a[n2].n++;
    a[n1].wi += o1;
    a[n2].wi += o2;
    a[n1].mi += o1 - o2;
    a[n2].mi += o2 - o1;
    if (o1 > o2)
      a[n1].sc += 3;
    else if (o2 > o1)
      a[n2].sc += 3;
    else
      a[n1].sc += 1, a[n2].sc += 1;
  }
  int ss = -1;
  for (int i = 0; i < m; i++)
    if (a[i].name == "BERLAND") ss = i;
  int s = -1;
  for (int i = 0; i < m; i++)
    if (a[i].name != "BERLAND" && a[i].n == 2) {
      s = i;
      break;
    }
  for (int k = 1; k <= 10; k++)
    for (int i = k; i <= 10; i++) {
      int j = i - k;
      int o1 = i, o2 = j, n1 = ss, n2 = s;
      a[n1].wi += o1;
      a[n2].wi += o2;
      a[n1].mi += o1 - o2;
      a[n2].mi += o2 - o1;
      if (o1 > o2)
        a[n1].sc += 3;
      else if (o2 > o1)
        a[n2].sc += 3;
      else
        a[n1].sc += 1, a[n2].sc += 1;
      int ans = 0;
      for (int l = 0; l < m; l++)
        if (big(l, ss)) ans++;
      if (ans <= 1) {
        cout << i << ':' << j;
        return 0;
      }
      a[n1].wi -= o1;
      a[n2].wi -= o2;
      a[n1].mi -= o1 - o2;
      a[n2].mi -= o2 - o1;
      if (o1 > o2)
        a[n1].sc -= 3;
      else if (o2 > o1)
        a[n2].sc -= 3;
      else
        a[n1].sc -= 1, a[n2].sc -= 1;
    }
  cout << "IMPOSSIBLE";
}

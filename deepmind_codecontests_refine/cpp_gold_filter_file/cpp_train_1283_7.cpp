#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
#pragma warning(default : 4)
using namespace std;
int n, m;
char c;
int w[100100], a[100100], p[100100], nk[100100], tnk, kl[100100];
vector<int> sk[100100];
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%c%d\n", &c, &a[i]);
    a[i]--;
    if (c == '+') {
      p[i] = 1;
      sk[a[i]].push_back(i);
    } else
      tnk++, nk[a[i]]++;
  }
  int pk = 0;
  for (int i = 0; i < n; i++) {
    if (sk[i].size() + tnk - nk[i] == m) {
      pk++;
      kl[i] = 1;
      for (int j = 0; j < sk[i].size(); j++) w[sk[i][j]]++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (p[i] == 0) {
      w[i] += pk;
      if (kl[a[i]]) w[i]--;
    }
    if (w[i] == 0) {
      puts("Lie");
    } else if (w[i] == pk) {
      puts("Truth");
    } else
      puts("Not defined");
  }
  return 0;
}

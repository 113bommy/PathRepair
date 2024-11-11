#include <bits/stdc++.h>
using namespace std;
int sa[100001], ba[100001];
int n, s;
int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) {
    char c;
    int p, q;
    scanf("%c", &c);
    scanf("%c %d %d", &c, &p, &q);
    if (c == 'B')
      ba[p] += q;
    else
      sa[p] += q;
  }
  int pos = 0;
  for (int i = 0, ts = s; i < 100001 && ts > 0; i++) {
    if (sa[i] > 0) {
      pos = i;
      ts--;
    }
  }
  for (int i = pos, ts = s; i >= 0 && ts > 0; i--) {
    if (sa[i] > 0) {
      printf("S %d %d\n", i, sa[i]);
      ts--;
    }
  }
  for (int i = 100001, ts = s; i >= 0 && ts > 0; i--) {
    if (ba[i] > 0) {
      printf("B %d %d\n", i, ba[i]);
      ts--;
    }
  }
  return 0;
}

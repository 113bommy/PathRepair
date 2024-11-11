#include <bits/stdc++.h>
using namespace std;
const int MAX = 100000;
const int INF = 1000000001;
int n;
int main(int argc, char *argv[]) {
  scanf("%d", &n);
  int tab[n];
  for (int i = 0; i < n; ++i) scanf("%d", tab + i);
  sort(tab, tab + n);
  int left = 350;
  for (int i = 0; i < n; ++i) {
    int m = min(left, tab[i]);
    left -= m;
    tab[i] -= m;
  }
  int solved = 0;
  int pen = 0;
  int s = 0;
  for (int i = 0; i < n; ++i) {
    s += tab[i];
    if (tab[i] <= 360) ++solved, pen += s;
  }
  printf("%d %d\n", solved, pen);
  return 0;
}

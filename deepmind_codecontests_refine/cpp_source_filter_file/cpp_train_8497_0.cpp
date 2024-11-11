#include <bits/stdc++.h>
using namespace std;
int h;
int seq[100010];
int par[100010];
int cur, cur_par, rem = -1, rem_par;
int main() {
  scanf("%d", &(h));
  for (int i = 0; i < h + 1; i++) scanf("%d", &(seq[i]));
  cur_par = 1;
  cur = 1;
  for (int i = 0; i < h; i++) {
    if (rem == -1 && seq[i] > 1 && seq[i + 1] > 1) {
      puts("ambiguous");
      rem = cur;
      rem_par = cur_par;
    }
    for (int j = 0; j < seq[i + 1]; j++) par[cur + j] = cur_par;
    cur += seq[i + 1];
    cur_par = cur;
  }
  if (rem == -1) {
    puts("perfect");
    return 0;
  }
  for (int i = 0; i < cur; i++) printf("%d ", par[i]);
  puts("");
  par[rem] = rem_par - 1;
  for (int i = 0; i < cur; i++) printf("%d ", par[i]);
}

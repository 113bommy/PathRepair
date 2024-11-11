#include <bits/stdc++.h>
using namespace std;
static const int INF = 500000000;
template <class T>
void debug(T a, T b) {
  for (; a != b; ++a) cerr << *a << ' ';
  cerr << endl;
}
int h, w, k;
char tmp[105];
int dif[105];
int bits[32];
int main() {
  scanf("%d%d%d", &h, &w, &k);
  int free1 = 0, free2 = 0;
  int n = 0;
  for (int i = 0; i < h; ++i) {
    scanf("%s", tmp);
    int ind1 = -1, ind2 = -1;
    for (int j = 0; j < w; ++j) {
      if (tmp[j] == 'R')
        ind1 = j;
      else if (tmp[j] == 'G')
        ind2 = j;
    }
    if (ind1 == -1 && ind2 == -1) continue;
    if (ind1 == -1) {
      for (int j = 0; j < w; ++j)
        if (tmp[j] == '.') free2 = 1;
      continue;
    }
    if (ind2 == -1) {
      for (int j = 0; j < w; ++j)
        if (tmp[j] == '.') free1 = 1;
      continue;
    }
    dif[n++] = abs(ind2 - ind1) - 1;
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 32; ++j)
      if (dif[i] >> j & 1) ++bits[j];
  if (free1 && free2) {
    puts("Draw");
  } else if (free1) {
    puts("First");
  } else if (free2) {
    puts("Second");
  } else {
    int ok = 0;
    for (int j = 0; j < 32; ++j)
      if (bits[j] % (k + 1)) ok = 1;
    if (ok)
      puts("First");
    else
      puts("Second");
  }
  return 0;
}

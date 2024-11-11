#include <bits/stdc++.h>
using namespace std;
long long din[101010];
long long part[101010];
char l[2000002], v[2000002];
int S1, S2, nextx[2000002], rez[1234], r, ras;
int vx[101010];
void make() {
  int k = 0;
  nextx[1] = 0;
  for (int x = 2; x <= S1; ++x) {
    while (k >= 1 && v[k + 1] != v[x]) k = nextx[k];
    if (v[k + 1] == v[x]) ++k;
    nextx[x] = k;
  }
}
int main() {
  scanf("%s%s", l + 1, v + 1);
  S1 = strlen(v + 1);
  S2 = strlen(l + 1);
  make();
  int k = 0;
  for (int i = 1; i <= S2; ++i) {
    while (k >= 1 && v[k + 1] != l[i]) k = nextx[k];
    if (v[k + 1] == l[i]) ++k;
    if (k == S1) {
      k = nextx[k];
      ++ras;
      vx[i]++;
    }
  }
  long long S = 0;
  long long last = 0;
  for (int i = 1; i <= S2; ++i) {
    if (vx[i] == 1) {
      for (int j = last; j < i - S1 + 1; ++j) {
        S += part[j];
        S %= 1000000009;
      }
      last = i - S1 + 1;
    }
    din[i] = last + S;
    din[i] %= 1000000009;
    part[i] = part[i - 1] + din[i];
    part[i] %= 1000000009;
  }
  printf("%I64d", part[S2]);
}

#include <bits/stdc++.h>
using namespace std;
string s;
int n, x;
int pop, akt;
int pocz, kon, mid;
int pos0, pos1;
string zam(string p, int a, int b) {
  for (int i = a; i <= b; i++) {
    p[i] = '1';
  }
  return p;
}
int main() {
  scanf("%d", &n);
  s = "";
  for (int i = 0; i < n; i++) {
    s += "0";
  }
  printf("? %s\n", s.c_str());
  fflush(stdout);
  scanf("%d", &pop);
  pocz = 0;
  kon = n - 1;
  while (pocz < kon) {
    mid = (pocz + kon + 1) / 2;
    printf("? %s\n", zam(s, mid, kon).c_str());
    fflush(stdout);
    scanf("%d", &akt);
    if (akt == pop + kon - mid + 1) {
      pos0 = mid;
      kon = mid - 1;
    } else if (akt == pop - kon + mid - 1) {
      pos1 = mid;
      kon = mid - 1;
    } else {
      pocz = mid;
    }
  }
  printf("! %d %d", pos0, pos1);
  fflush(stdout);
}

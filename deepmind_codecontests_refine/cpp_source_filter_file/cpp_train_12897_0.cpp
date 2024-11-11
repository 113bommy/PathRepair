#include <bits/stdc++.h>
using namespace std;

class data {
  int p[5]={1868,1912,1926,1989,2017};
  char c[4]={'M','T','S','H'};
};
int main() {
  int E, Y;
  cin >> E >> Y;
  data d;
  if (E==0) {
    int idx;
    for (int i=0; i<4; i++) {
      if (d.p[i]<=Y && Y<d.p[i+1]) {
        idx = i;
        break;
      }
    }
    printf("%c%d\n", d.c[idx], Y-d.p[idx]+1);
  } else {
    printf("%d\n", Y+d.p[E-1]-1);
  }
  return 0;
}
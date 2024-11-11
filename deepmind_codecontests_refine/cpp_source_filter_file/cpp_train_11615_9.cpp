#include <bits/stdc++.h>
using namespace std;
int n;
char ti[10];
int main() {
  scanf("%d", &n);
  scanf("%s", ti);
  if (ti[3] >= '6') ti[3] = '0';
  if (n == 12) {
    if (ti[0] == '1' && ti[1] > '2')
      ti[0] = '0';
    else if (ti[0] > '1') {
      if (ti[1] == '0')
        ti[0] = '1';
      else
        ti[0] = '0';
    } else if (ti[0] == '0' && ti[1] == '0')
      ti[0] = '1';
  } else {
    if (ti[0] == '2' && ti[1] >= 4)
      ti[0] = '0';
    else if (ti[0] > '2')
      ti[0] = '0';
  }
  printf("%s", ti);
  return 0;
}

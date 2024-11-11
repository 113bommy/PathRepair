#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int steps[N], n;
bool flags[N];
char directions[N];
void fun(char d, int s, int po) {
  if (flags[po]) {
    puts("INFINTE");
    exit(0);
  }
  flags[po] = true;
  if (d == '>') {
    if (po + steps[po] >= n) {
      puts("FINITE");
      exit(0);
    } else
      fun(directions[po + steps[po]], steps[po + steps[po]], po + steps[po]);
  } else {
    if (po - steps[po] < 0) {
      puts("FINITE");
      exit(0);
    } else
      fun(directions[po - steps[po]], steps[po - steps[po]], po - steps[po]);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) cin >> directions[i];
  for (int i = 0; i < n; ++i) scanf("%d", &steps[i]);
  fun(directions[0], steps[0], 0);
  return 0;
}

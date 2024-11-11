#include <bits/stdc++.h>
using namespace std;
long long l[100005];
long long c[100005];
long long c2[100005];
char t[100005];
int main() {
  int n;
  long long time = 0;
  long long lg = 0;
  long long lw = 0;
  long long lla = 0;
  long long energy = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &l[i]);
  scanf("%s", t);
  for (int i = 0; i < n; i++) {
    if (t[i] == 'G') {
      lg += l[i];
      energy += l[i];
      time += l[i] * 5;
    }
    if (t[i] == 'W') {
      lw += l[i];
      energy += l[i];
      time += l[i] * 3;
    }
    if (t[i] == 'L') {
      lla += l[i];
      if (energy >= l[i])
        energy -= l[i];
      else {
        if (lw > 0)
          time += (l[i] - energy) * 3;
        else
          time += (l[i] - energy) * 5;
        energy = 0;
      }
      time += l[i];
    }
    c[i] = energy;
  }
  c2[n - 1] = c[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    c2[i] = min(c2[i + 1], c[i]);
  }
  long long used = 0;
  for (int i = 0; i < n; i++) {
    if (t[i] == 'G') {
      if (l[i] * 2 <= (c2[i] - used)) {
        used += l[i] * 2;
        time -= l[i] * 4;
      } else {
        time -= (c2[i] - used) * 2;
        used = c2[i];
      }
    }
  }
  time -= c[n - 1] - used;
  printf("%lld", time);
}

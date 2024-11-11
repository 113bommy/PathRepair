#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[300004];
int n, nr, r, Min, poz, f1, f2, ch1, ch2, sol, soli, sol2, i, j, l, v[300004],
    m[300004];
char s[300004], b[300004];
bool ok1, ok2;
int main() {
  scanf("%d", &n);
  scanf("%s", &s);
  nr = 0;
  Min = 1000000000;
  for (i = 0; i < n; i++) {
    if (s[i] == '(')
      nr++;
    else
      nr--;
    v[i] = nr;
    Min = min(Min, v[i]);
    m[i] = Min;
  }
  if (v[n - 1] != 0) {
    printf("%d\n%d %d\n", 0, 1, 1);
    return 0;
  }
  poz = 0;
  if (m[n - 1] < 0) {
    nr = 0;
    poz = -1;
    for (i = (n - 1); i > 0; i--) {
      if (s[i] == '(')
        nr++;
      else
        nr--;
      if ((nr + m[i - 1]) >= 0) {
        poz = i;
        break;
      }
    }
    nr = -1;
    for (j = poz; j < n; j++) b[++nr] = s[j];
    for (j = 0; j < poz; j++) b[++nr] = s[j];
  } else {
    for (i = 0; i < n; i++) b[i] = s[i];
  }
  l = 0;
  r = 0;
  sol = 0;
  ch1 = 1;
  ch2 = 1;
  nr = 0;
  for (i = 0; i < n; i++) {
    if (b[i] == '(')
      nr++;
    else
      nr--;
    v[i] = nr;
    Min = min(Min, v[i]);
    m[i] = Min;
    if (nr == 0) {
      sol++;
      a[++r].first = l;
      a[r].second = i;
      l = i + 1;
    }
  }
  soli = sol;
  for (i = 1; i <= r; i++) {
    sol2 = 0;
    nr = 0;
    ok1 = false;
    ok2 = false;
    for (j = a[i].first + 1; j < a[i].second; j++) {
      if (b[j] == '(') {
        nr++;
        if (!ok1) {
          f1 = j;
          ok1 = true;
        }
      } else {
        nr--;
        if (!ok2) {
          f2 = j;
          ok2 = true;
        }
      }
      if (nr == 0) sol2++;
    }
    if ((sol2 + 1) > sol) {
      sol = sol2 + 1;
      ch1 = a[i].first;
      ch2 = a[i].second;
    }
    sol2 = 0;
    nr = 0;
    f2 = a[i].first + 1;
    for (j = a[i].first + 1; j < a[i].second; j++) {
      if (b[j] == '(') {
        nr++;
        if (!ok1) {
          f1 = j;
          ok1 = true;
        }
      } else {
        nr--;
        if (!ok2) {
          f2 = j;
          ok2 = true;
        }
      }
      if (nr == 0) {
        if ((sol2 + soli) > sol) {
          sol = sol2 + soli;
          ch1 = f2;
          ch2 = j;
        }
        sol2 = 0;
        f2 = j + 1;
      }
      if (nr == 1) sol2++;
    }
  }
  ch1 = (ch1 + poz) % n + 1;
  ch2 = (ch2 + poz) % n + 1;
  printf("%d\n%d %d", sol, ch1, ch2);
  return 0;
}

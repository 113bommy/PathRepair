#include <bits/stdc++.h>
using namespace std;
int ojciec[200100], ojciec1[200100], r[200100], s[200100], tab[200100],
    wazne[200100], suma[200100];
bool czy[200100];
int Find1(int a) {
  if (ojciec1[a] != a) ojciec1[a] = Find1(ojciec1[a]);
  return ojciec1[a];
}
void junion1(int a, int b) {
  a = Find1(a);
  b = Find1(b);
  ojciec1[b] = a;
}
int Find(int a) {
  if (ojciec[a] != a) ojciec[a] = Find(ojciec[a]);
  return ojciec[a];
}
void junion(int a, int b) {
  a = Find(a);
  b = Find(b);
  ojciec[b] = a;
}
int main() {
  int n, m, p;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &tab[i]);
  sort(tab, tab + n);
  for (int i = 0; i < n; ++i) {
    ojciec[i] = i;
    ojciec1[i] = i;
    if (i != 0 && tab[i - 1] + 1 == tab[i]) {
      junion(i - 1, i);
      junion1(i, i - 1);
    }
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d", &wazne[i]);
    czy[wazne[i]] = true;
  }
  for (int i = 1; i < 200100; ++i) {
    if (czy[i])
      suma[i] = suma[i - 1] + 1;
    else
      suma[i] = suma[i - 1];
  }
  sort(wazne, wazne + m);
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      r[i] = max(r[i], r[i - 1]);
      s[i] = r[i - 1];
    }
    for (int j = 0; j < m && wazne[j] <= tab[i]; ++j) {
      if (i - (tab[i] - wazne[j]) >= 0) {
        p = Find(i - (tab[i] - wazne[j]));
        if (p - 1 >= 0) {
          s[i] =
              max(s[i], suma[tab[i]] - suma[tab[i] - (i - p + 1)] + r[p - 1]);
        } else
          s[i] = max(s[i], suma[tab[i]] - suma[tab[i] - (i - p + 1)]);
      }
    }
    for (int j = m - 1; j >= 0 && wazne[j] > tab[i]; --j) {
      if (wazne[j] - tab[j] + i < n) {
        p = Find1(i + (wazne[j] - tab[i]));
        r[p] = max(r[p], suma[tab[i] + p - i] - suma[tab[i]] + s[i]);
      }
    }
    r[i] = max(r[i], s[i]);
  }
  printf("%d", r[n - 1]);
}

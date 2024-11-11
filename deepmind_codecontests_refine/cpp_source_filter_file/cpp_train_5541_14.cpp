#include <bits/stdc++.h>
using namespace std;
ifstream f("date.in");
int n, m, v[101], lwst, hghst, k;
struct fruit {
  char name[30];
  int items = 0;
} a[101];
int fnd(char den[]) {
  for (int i = 1; i <= k; i++)
    if (strcmp(a[i].name, den) == 0) return i;
  return -1;
}
bool cmp(fruit x, fruit y) {
  if (x.items < y.items) return true;
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> v[i];
  for (int i = 1; i <= m; i++) {
    char den[30];
    cin >> den;
    int idx = fnd(den);
    if (idx != -1)
      a[idx].items++;
    else {
      strcpy(a[++k].name, den);
      a[k].items = 1;
    }
  }
  sort(a + 1, a + k + 1, cmp);
  sort(v + 1, v + n + 1);
  int p = 1;
  int obst = k;
  while (p <= n && obst >= 1) {
    lwst += a[obst].items * v[p];
    hghst += a[obst].items * v[n - p + 1];
    p++;
    obst--;
  }
  cout << lwst << " " << hghst;
}

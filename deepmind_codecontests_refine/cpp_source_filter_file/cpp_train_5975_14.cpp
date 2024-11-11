#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n;
struct Data {
  int s, id;
  bool operator<(const Data &a) const { return s < a.s; }
} da[N];
int a[N], b[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int s;
    scanf("%d", &s);
    da[i] = Data{s, i};
  }
  sort(da, da + n);
  for (int i = 0; i < (n + 2) / 3; i++) {
    a[da[i].id] = i;
    b[da[i].id] = da[i].s - i;
  }
  int x = (n + 2) / 3;
  for (int i = x; i < x + x; i++) {
    a[da[i].id] = 0;
    b[da[i].id] = da[i].s;
  }
  for (int i = x + x; i < n; i++) {
    a[da[i].id] = da[i].s - (n - i - 1);
    b[da[i].id] = n - i - 1;
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    printf("%d%c", a[i], " \n"[i == n - 1]);
  }
  for (int i = 0; i < n; i++) {
    printf("%d%c", b[i], " \n"[i == n - 1]);
  }
  return 0;
}

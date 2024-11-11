#include <bits/stdc++.h>
using namespace std;
struct e {
  int diff, ind;
} st[1000010];
int n, a[1000010], rez[1000010];
bool srt(e aa, e bb) { return (aa.diff < bb.diff); }
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    st[i].ind = i;
    st[i].diff = a[i] + a[(i + 1) % n];
  }
  sort(st, st + n, srt);
  for (int i = 0; i < n; i++) {
  }
  for (int i = 0; i < n; i++) rez[st[i].ind] = i;
  for (int i = 0; i < n; i++) printf("%d ", rez[i]);
  return 0;
}

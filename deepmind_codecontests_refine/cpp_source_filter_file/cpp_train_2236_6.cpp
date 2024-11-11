#include <bits/stdc++.h>
using namespace std;
const int N = (int)5e5 + 1;
int n, k;
long long s, m;
long long t[N];
void shift_down(int i) {
  int l = i * 2, r = l + 1, m = i;
  if (l <= k && t[l] < t[m]) m = l;
  if (r <= k && t[r] < t[m]) m = r;
  if (m != i) {
    swap(t[m], t[i]);
    shift_down(m);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &s, &m);
    t[1] = max(t[1], s) + m;
    printf("%d\n", t[1]);
    shift_down(1);
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N = 4000000;
bool in[N + 1], flag[N + 1];
long long a[N + 1];
int L[N + 1], R[N + 1];
pair<long long, int> vp[N];
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
long long rll() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
int main() {
  int n = ri(), k = ri(), nn = 0;
  for (int i = (0); i < (n); i++) a[i] = rll();
  for (int i = (0); i < (n - 1); i++) {
    a[nn] = a[i + 1] - a[i];
    if (!nn && a[0] <= 0)
      ;
    else if (nn && (a[nn - 1] > 0) == (a[nn] > 0))
      a[nn - 1] += a[nn];
    else
      nn++;
  }
  while (nn && a[nn - 1] <= 0) nn--;
  if (!nn) return puts("0");
  a[nn] = 0;
  for (int i = (0); i < (nn); i++) L[i] = i - 1, R[i] = i + 1;
  L[0] = nn, R[nn] = 0;
  L[nn] = nn - 1;
  stack<int> can;
  for (;;) {
    int nvp = 0;
    for (int i = R[nn]; i != nn; i = R[i])
      if (!flag[i]) vp[nvp++] = pair<long long, int>(abs(a[i]), i);
    if (nvp <= 2 * k) break;
    int rm = (nvp - 2 * k + 1) / 2;
    nth_element(vp, vp + rm - 1, vp + nvp);
    pair<long long, int> pivot = vp[rm - 1];
    auto add = [&](int x) {
      if (!in[x] && pair<long long, int>(abs(a[x]), x) <= pivot) {
        in[x] = true;
        can.push(x);
      }
    };
    for (int i = R[nn]; i != nn; i = R[i]) add(i);
    while (!can.empty()) {
      int x = can.top();
      can.pop();
      in[x] = false;
      int l = L[x], r = R[x];
      if (flag[x] || l < nn && abs(a[x]) > abs(a[l]) ||
          r < nn && abs(a[x]) > abs(a[r]))
        continue;
      flag[l] = flag[r] = true;
      L[x] = l < nn ? L[l] : nn;
      R[x] = r < nn ? R[r] : nn;
      R[L[x]] = L[R[x]] = x;
      a[x] += a[l] + a[r];
      if (l == nn) {
        flag[x] = true;
        L[R[nn] = R[x]] = nn;
      }
      if (r == nn) {
        flag[x] = true;
        R[L[nn] = L[x]] = nn;
      }
      if (L[x] < nn) add(L[x]);
      if (R[x] < nn) add(R[x]);
      add(x);
    }
  }
  long long sum = 0;
  for (int i = R[nn]; i != nn; i = R[i])
    if (a[i] > 0) sum += a[i];
  printf("%I64d\n", sum);
}

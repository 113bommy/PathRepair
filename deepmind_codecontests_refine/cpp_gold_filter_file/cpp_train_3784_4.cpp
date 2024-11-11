#include <bits/stdc++.h>
int n, p[300001], ip[300001], B, s[300001], cnt[100][600001], *Cnt[200],
    tag[200];
void add(int r, int x) {
  int b = r / B;
  for (int i = 0; i < b; i++) tag[i] += x;
  for (int i = b * B; i < r; i++) {
    Cnt[b][s[i]]--;
    s[i] += x;
    Cnt[b][s[i]]++;
  }
}
long long sum(int r) {
  long long S = 0;
  for (int i = 0; i <= r / B; i++) {
    S += Cnt[i][1 - tag[i]] + Cnt[i][2 - tag[i]];
  }
  return S;
}
int main() {
  scanf("%d", &n);
  B = (n + 99) / 100;
  for (int i = 0; i < n; i++) scanf("%d", ip + i), p[--ip[i]] = i;
  for (int i = 0; i < 100; i++) Cnt[i] = cnt[i] + 300000, Cnt[i][0] = B;
  s[0] = 1;
  Cnt[0][1]++;
  Cnt[0][0]--;
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    int list[2], top = 0;
    if (p[i] - 1 >= 0 && ip[p[i] - 1] < i) list[top++] = ip[p[i] - 1];
    if (p[i] + 1 < n && ip[p[i] + 1] < i) list[top++] = ip[p[i] + 1];
    add(i, 1);
    if (top >= 1) add(list[0] + 1, -1);
    if (top >= 2) add(list[1] + 1, -1);
    ans += sum(i);
    s[i] = 1;
    Cnt[i / B][0]--;
    Cnt[i / B][1]++;
  }
  printf("%I64d", ans);
}

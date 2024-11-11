#include <bits/stdc++.h>
inline void read(int &sum) {
  register char ch = getchar();
  for (sum = 0; ch < '0' || ch > '9'; ch = getchar())
    ;
  for (; ch >= '0' && ch <= '9';
       sum = (sum << 1) + (sum << 3) + ch - '0', ch = getchar())
    ;
}
const int N = 300010;
const int M = 17;
const int Inf = 0x3f3f3f3f;
int bini[M], maxi[N][M], mini[N][M], logi[N];
int n, m, a[N], TTT[N << 2], q[N], head, tail;
long long ans;
inline int Min(int x, int y) { return x < y ? x : y; }
inline int Max(int x, int y) { return x > y ? x : y; }
inline void Init_ST() {
  logi[0] = -1;
  for (int i = 1; i <= n; i++) logi[i] = logi[i >> 1] + 1;
  bini[0] = 1;
  for (int i = 1; i < M; i++) bini[i] = bini[i - 1] << 1;
  for (int i = 1; i <= n; i++) mini[i][0] = maxi[i][0] = a[i];
  for (int i = 1; i < M; i++)
    for (int j = 1; j + bini[i] - 1 <= n; j++)
      mini[j][i] = Min(mini[j][i - 1], mini[j + bini[i - 1]][i - 1]),
      maxi[j][i] = Max(maxi[j][i - 1], maxi[j + bini[i - 1]][i - 1]);
}
inline int get_Min(int l, int r) {
  int len = logi[r - l + 1];
  return Min(mini[l][len], mini[r - bini[len] + 1][len]);
}
inline int get_Max(int l, int r) {
  int len = logi[r - l + 1];
  return Max(maxi[l][len], maxi[r - bini[len] + 1][len]);
}
void Burn_out(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  Burn_out(l, mid), Burn_out(mid + 1, r);
  register int Temp_Max = -Inf, Temp_Min = Inf, i, len, pos, temp;
  for (i = mid; i >= l; i--) {
    Temp_Max = Max(Temp_Max, a[i]), Temp_Min = Min(Temp_Min, a[i]),
    len = Temp_Max - Temp_Min + 1, pos = len - (mid - i + 1) + mid;
    if (pos <= r && pos > mid && get_Min(mid + 1, pos) >= Temp_Min &&
        get_Max(mid + 1, pos) <= Temp_Max)
      ans++;
  }
  Temp_Max = -Inf, Temp_Min = Inf;
  for (i = mid + 1; i <= r; i++) {
    Temp_Max = Max(Temp_Max, a[i]), Temp_Min = Min(Temp_Min, a[i]),
    len = Temp_Max - Temp_Min + 1, pos = len - (i - mid), pos = mid - pos + 1;
    if (pos >= l && pos <= mid && get_Min(pos, mid) >= Temp_Min &&
        get_Max(pos, mid) <= Temp_Max)
      ans++;
  }
  head = 1, tail = 0, Temp_Max = -Inf, Temp_Min = Inf, temp = mid;
  for (i = mid + 1; i <= r; i++) {
    Temp_Max = Max(Temp_Max, a[i]), Temp_Min = Min(Temp_Min, a[i]);
    while (temp >= l && get_Max(temp, mid) <= Temp_Max)
      q[++tail] = temp, TTT[get_Min(temp, mid) - temp + 300000]++, temp--;
    while (head <= tail && get_Min(q[head], mid) >= Temp_Min)
      TTT[get_Min(q[head], mid) - q[head] + 300000]--, head++;
    ans += TTT[Temp_Max - i + 300000];
  }
  while (head <= tail) TTT[get_Min(q[head], mid) - q[head] + 300000]--, head++;
  head = 1, tail = 0, Temp_Max = -Inf, Temp_Min = Inf, temp = mid + 1;
  for (i = mid; i >= l; i--) {
    Temp_Max = Max(Temp_Max, a[i]), Temp_Min = Min(Temp_Min, a[i]);
    while (temp <= r && get_Max(mid + 1, temp) <= Temp_Max)
      q[++tail] = temp, TTT[get_Min(mid + 1, temp) + temp + 300000]++, temp++;
    while (head <= tail && get_Min(mid + 1, q[head]) >= Temp_Min)
      TTT[get_Min(mid + 1, q[head]) + q[head] + 300000]--, head++;
    ans += TTT[Temp_Max + i + 300000];
  }
  while (head <= tail)
    TTT[get_Min(mid + 1, q[head]) + q[head] + 300000]--, head++;
}
int main() {
  read(n), ans = n;
  for (int i = 1, x, y; i <= n; i++) read(x), read(y), a[x] = y;
  Init_ST(), Burn_out(1, n);
  printf("%lld", ans);
}

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100002;
long long x;
int a[MAXN], b_indexes[MAXN], a_indexes[MAXN];
bool b[MAXN];
long long get_next_x() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
bool CmpMySort(int i1, int i2) { return a[i1] > a[i2]; }
int main() {
  int i, j;
  int n, d;
  int index[MAXN];
  cin >> n >> d >> x;
  for (i = 0; i < n; i++) {
    a[i] = i + 1;
    index[i] = i;
  }
  for (i = 0; i < n; i++) swap(a[i], a[get_next_x() % (i + 1)]);
  sort(index, index + n, CmpMySort);
  for (i = 0; i < d; i++) b[i] = true;
  for (i = d; i < n; i++) b[i] = false;
  for (i = 0; i < n; i++) swap(b[i], b[get_next_x() % (i + 1)]);
  j = 0;
  for (i = 0; i < n; i++)
    if (b[i]) b_indexes[j++] = i;
  b_indexes[j] = MAXN + 1;
  int rest = n;
  int last = n;
  int ans[MAXN];
  for (i = 0; i < n; i++) ans[i] = -1;
  for (i = 0; i < n && rest > 0; i++) {
    for (j = 0; index[i] + b_indexes[j] < last && j < d; j++) {
      int num = index[i] + b_indexes[j];
      if (ans[num] == -1) {
        ans[num] = a[index[i]];
        rest--;
        while (last > 0 && ans[last - 1] != -1) last--;
      }
    }
  }
  for (i = 0; i < n; i++) printf("%d", ((ans[i] == -1) ? 0 : ans[i]));
}

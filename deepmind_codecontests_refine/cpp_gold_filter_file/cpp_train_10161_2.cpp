#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 123;
const int M = 50 + 2;
struct Tdata {
  int value, num;
  bool operator<(const Tdata &a) const { return value > a.value; }
};
Tdata datas[M];
int n, m;
int i, j, k;
int ans[N];
void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    for (i = 0; i < m; ++i) {
      scanf("%d", &datas[i].value);
      datas[i].num = i + 1;
    }
    sort(datas, datas + m);
    int toa = 0;
    int summ = 0;
    int ei;
    for (i = 0; i < m; ++i) {
      if (summ + datas[i].value < n / 2) {
        for (summ += datas[i].value; datas[i].value > 0; datas[i].value--) {
          ans[toa] = datas[i].num;
          toa += 2;
        }
      } else {
        for (int ta = n / 2 - summ; ta > 0; ta--, datas[i].value--) {
          ans[toa] = datas[i].num;
          toa += 2;
        }
        ei = i;
        break;
      }
    }
    if (toa / 2 < n / 2) {
      puts("-1");
      continue;
    }
    toa = 1;
    summ = 0;
    for (i = ei; i < m; ++i) {
      if (datas[i].num == ans[0] || datas[i].num == ans[2]) continue;
      if (summ + datas[i].value < n / 2) {
        for (summ += datas[i].value; datas[i].value > 0; datas[i].value--) {
          ans[toa] = datas[i].num;
          toa += 2;
        }
      } else {
        for (int ta = n / 2 - summ; ta > 0; ta--, datas[i].value--) {
          ans[toa] = datas[i].num;
          toa += 2;
        }
        break;
      }
    }
    if (toa < n) {
      puts("-1");
      continue;
    }
    if (n & 1) {
      bool canswap = false;
      for (i = 0; i < m; ++i)
        if (datas[i].value > 0) {
          int ni = datas[i].num;
          if (ni != ans[0] && ni != ans[n - 2]) {
            ans[n - 1] = ni;
            canswap = true;
            break;
          }
          for (j = 1; j < n - 2 && !canswap; ++j)
            if (ni != ans[j - 1] && ni != ans[j + 1] && ans[j] != ans[0] &&
                ans[j] != ans[n - 2]) {
              ans[n - 1] = ans[j];
              ans[j] = ni;
              canswap = true;
              break;
            }
          if (!canswap && ni != ans[1] && ni != ans[0]) {
            ans[n - 1] = ans[0];
            ans[0] = ni;
            canswap = true;
          }
          if (!canswap && ni != ans[n - 2] && ni != ans[n - 3]) {
            ans[n - 1] = ans[n - 2];
            ans[n - 2] = ni;
            canswap = true;
          }
          if (canswap) break;
        }
      if (!canswap) {
        puts("-1");
        continue;
      }
    }
    for (i = 0; i < n; ++i) printf("%d%s", ans[i], (i == n - 1) ? "\n" : " ");
  }
  return 0;
}

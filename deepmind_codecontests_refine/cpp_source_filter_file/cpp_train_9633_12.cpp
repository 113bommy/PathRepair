#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;
const int pot = 1024 * 1024;
int tr_max[2 * pot], tr_min[2 * pot];
int fi(int low, int n) {
  low += pot;
  int already_min = tr_min[low];
  int already_max = tr_max[low];
  if (already_min <= already_max) return min(already_min, already_max);
  while (low % 2 == 1 || min(already_min, tr_min[low + 1]) >
                             max(already_max, tr_max[low + 1])) {
    if (low % 2 == 0) {
      already_min = min(already_min, tr_min[low + 1]);
      already_max = max(already_max, tr_max[low + 1]);
    }
    low /= 2;
  }
  ++low;
  while (low < pot) {
    if (min(already_min, tr_min[low * 2]) > max(already_max, tr_max[low * 2])) {
      already_min = min(already_min, tr_min[low * 2]);
      already_max = max(already_max, tr_max[low * 2]);
      low = 2 * low + 1;
    } else
      low = 2 * low;
  }
  int ans = min(already_min, already_max);
  if (low < pot + n)
    ans = max(
        ans, min(min(already_min, tr_min[low]), max(already_max, tr_max[low])));
  return ans;
}
int ans[nax];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = (0); i <= ((n)-1); ++i) {
    int x;
    scanf("%d", &x);
    tr_max[pot + i] = x * 100;
  }
  for (int i = (0); i <= ((n)-1); ++i) {
    int x;
    scanf("%d", &x);
    tr_min[pot + i] = x;
  }
  tr_min[pot + n] = -inf;
  tr_max[pot + n] = inf;
  for (int i = (pot - 1); i >= (1); --i)
    tr_max[i] = max(tr_max[2 * i], tr_max[2 * i + 1]);
  for (int i = (pot - 1); i >= (1); --i)
    tr_min[i] = min(tr_min[2 * i], tr_min[2 * i + 1]);
  for (int i = (0); i <= ((n)-1); ++i) ans[i] = fi(i, n);
  sort(ans, ans + n);
  long double rem = 1;
  int ludzie = n;
  long double answer = 0;
  for (int i = (0); i <= ((n)-1); ++i) {
    if (k > ludzie) break;
    long double with = (long double)k / ludzie;
    --ludzie;
    answer += with * ans[i] * rem;
    rem -= with;
  }
  printf("%.10lf\n", (double)answer);
  return 0;
}

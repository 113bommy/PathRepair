#include <bits/stdc++.h>
using namespace std;
const int inf = 2100000000;
const int mod = 1000000007;
int N;
long long int R;
vector<long long int> L, T;
int main() {
  scanf("%d %I64d", &N, &R);
  L = T = vector<long long int>(N);
  for (int i = 0; i < N; i++) {
    scanf("%I64d", &L[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%I64d", &T[i]);
  }
  long long int r = 0, t = 0;
  int pos = 0;
  long long int ans = 0;
  vector<long long int> tm;
  while (pos < N) {
    if (r) {
      if (L[pos] <= r) {
        if (T[pos] < L[pos]) {
          printf("-1");
          return 0;
        }
        T[pos] -= L[pos];
        r -= L[pos];
        t += L[pos];
        pos++;
      } else {
        if (T[pos] < r) {
          printf("-1");
          return 0;
        }
        L[pos] -= r;
        T[pos] -= r;
        t += r;
        r = 0;
        if (T[pos] < L[pos]) {
          printf("-1");
          return 0;
        }
        if (2 * L[pos] <= T[pos]) {
          t += 2 * L[pos];
          pos++;
          continue;
        }
        long long int l2 = T[pos] - L[pos];
        L[pos] -= l2;
        T[pos] -= 2 * l2;
        t += 2 * l2;
        long long int n = L[pos] / R;
        if (L[pos] % R) n++;
        ans += n;
        if (ans <= 100000) {
          for (long long int i = 0; i < n; i++) {
            tm.push_back(t + R * i);
          }
        }
        if (R * n > L[pos]) {
          r = R * n - L[pos];
          t += L[pos];
        } else {
          r = 0;
          t += R * n + (L[pos] - R * n) * 2;
        }
        pos++;
      }
    } else {
      if (T[pos] < L[pos]) {
        printf("-1");
        return 0;
      }
      if (2 * L[pos] <= T[pos]) {
        t += 2 * L[pos];
        pos++;
        continue;
      }
      long long int l2 = T[pos] - L[pos];
      L[pos] -= l2;
      T[pos] -= 2 * l2;
      t += 2 * l2;
      long long int n = L[pos] / R;
      if (L[pos] % R) n++;
      ans += n;
      if (ans <= 100000) {
        for (long long int i = 0; i < n; i++) {
          tm.push_back(t + R * i);
        }
      }
      if (R * n > L[pos]) {
        r = R * n - L[pos];
        t += L[pos];
      } else {
        r = 0;
        t += R * n + (L[pos] - R * n) * 2;
      }
      pos++;
    }
  }
  printf("%I64d\n", ans);
  if (ans > 100000) return 0;
  for (int i = 0; i < tm.size(); i++) {
    printf("%I64d ", tm[i]);
  }
}

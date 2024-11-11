#include <bits/stdc++.h>
using namespace std;
clock_t start_clock;
void Time() {
  clock_t end_clock = clock();
  double elapsed_time =
      ((double)end_clock - (double)start_clock) / (double)CLOCKS_PER_SEC;
  fprintf(stderr, "Time elapsed = %0.4lf\n", elapsed_time);
}
char s[510 * 2];
int ps[510 * 2], nxt[510 * 2];
int beauty(int N) {
  vector<int> vec;
  for (int i = N; i >= 0; --i) {
    while (!vec.empty() and ps[vec.back()] >= ps[i]) {
      vec.pop_back();
    }
    if (!vec.empty())
      nxt[i] = vec.back();
    else
      nxt[i] = N + 1;
    vec.push_back(i);
  }
  int n = N / 2, ret = 0;
  for (int i = 0; i < n; ++i) {
    ret += (nxt[i] > i + n && ps[i] == ps[i + n]);
  }
  return ret;
}
int main() {
  int n;
  scanf("%d %s", &n, s);
  vector<int> pos0, pos1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      pos0.push_back(i);
    else
      pos1.push_back(i);
  }
  int ans = 0, l = 0, r = 0;
  ps[0] = 0;
  for (int i = 1; i <= n + n; ++i) {
    if (i <= n)
      ps[i] = ps[i - 1] + 2 * (s[i - 1] == '(') - 1;
    else
      ps[i] = ps[i - 1] + 2 * (s[i - n - 1] == '(') - 1;
  }
  ans = beauty(2 * n);
  for (int i = 0; i < pos0.size(); ++i) {
    for (int j = 0; j < pos1.size(); ++j) {
      if (pos0[i] < pos1[j]) {
        for (int k = pos0[i] + 1; k <= pos1[j]; ++k) {
          ps[k] -= 2;
          ps[k + n] -= 2;
        }
      } else {
        for (int k = pos1[j] + 1; k <= pos0[i]; ++k) {
          ps[k] += 2;
          ps[k + n] += 2;
        }
      }
      int res = beauty(2 * n);
      if (res > ans) {
        ans = res;
        l = pos0[i];
        r = pos1[j];
      }
      if (pos0[i] < pos1[j]) {
        for (int k = pos0[i] + 1; k <= pos1[j]; ++k) {
          ps[k] += 2;
          ps[k + n] += 2;
        }
      } else {
        for (int k = pos1[j] + 1; k <= pos0[i]; ++k) {
          ps[k] -= 2;
          ps[k + n] -= 2;
        }
      }
    }
  }
  printf("%d\n%d %d\n", ans, l + 1, r + 1);
  Time();
  return 0;
}

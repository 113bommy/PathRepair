#include <bits/stdc++.h>
using namespace std;
const int N = 1000050;
const long long Mod = 10007;
const int inf = 0x3f3f3f3f;
int n, a[100050], r[100050], l[100050];
int main(int argc, const char* argv[]) {
  scanf("%d", &n);
  for (int i = 1; i < ((n) + 1); i++) scanf("%d%d", &a[i], &l[i]);
  a[n + 1] = 0x7f3f3f3f;
  int cnt = 1;
  r[1] = a[1];
  for (int i = 2; i < ((n) + 1); i++) {
    if (a[i] - l[i] > r[i - 1]) {
      r[i] = a[i];
      cnt++;
    } else if (a[i] + l[i] < a[i + 1]) {
      r[i] = a[i] + l[i];
      cnt++;
    } else
      r[i] = a[i];
  }
  printf("%d\n", cnt);
  return 0;
}

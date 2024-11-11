#include <bits/stdc++.h>
using namespace std;
long long st[1000005 + 1];
long long dr[1000005 + 1];
int v[1000005 + 1];
int N, M;
int main() {
  int i, cnt;
  long long res = 1LL << 62, temp;
  scanf("%d %d", &N, &M);
  for (i = 1; i <= N; i++) scanf("%d", &v[i]);
  st[1] = 2 * v[1];
  for (i = 2; i <= N; i++)
    if (i % M == 1 % M)
      st[i] = st[i - M] + 2 * v[i];
    else
      st[i] = st[i - 1];
  dr[N] = 2 * v[N];
  for (i = 2; i <= N; i++)
    if (i % M == 1 % M)
      dr[N - i + 1] = dr[N - i + 1 + M] + 2 * v[N - i + 1];
    else
      dr[N - i + 1] = dr[N - i + 2];
  for (i = 1; i <= N; i++) {
    cnt = (i + M - 2) / M;
    temp = 2LL * cnt * v[i] - st[i - 1];
    cnt = (N - i + M - 1) / M;
    temp = temp + dr[i + 1] - 2LL * cnt * v[i];
    res = min(res, temp);
  }
  cout << res;
  return 0;
}

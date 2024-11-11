#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;
int N, Q, t, L, R, cnt[MAX + 1], p[MAX + 1];
long long pre[MAX + 1], f[MAX + 1];
void sieve() {
  for (int i = 2; i <= MAX; i++)
    if (p[i]) {
      f[i] += cnt[i];
      for (int j = i * 2; j <= MAX; j += i) {
        p[j] = 0;
        f[i] += cnt[j];
      }
    }
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    scanf("%d", &t);
    cnt[t]++;
  }
  sieve();
  cin >> Q;
  for (int i = 1; i <= MAX; i++) pre[i] = pre[i - 1] + f[i];
  while (Q--) {
    cin >> L >> R;
    L = min(L, MAX);
    R = min(R, MAX);
    cout << pre[R] - pre[L - 1] << endl;
  }
  return 0;
}

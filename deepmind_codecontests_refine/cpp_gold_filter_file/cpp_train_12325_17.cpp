#include <bits/stdc++.h>
using namespace std;
int N, K;
int A[5002];
int cnt[1000002], F[1000002];
int main() {
  srand(time(0));
  cin.sync_with_stdio(false);
  cin >> N >> K;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  for (int i = 1; i <= N; ++i)
    for (int j = i + 1; j <= N; ++j) ++cnt[max(A[i], A[j]) - min(A[i], A[j])];
  int limit = K * (K + 1) / 2;
  for (int i = 1; i <= 1000001; ++i) {
    bool ok = true;
    int total = 0;
    for (int j = i; j <= 1000000 && ok; j += i) {
      total += cnt[j];
      if (total > limit) {
        ok = false;
        break;
      }
    }
    int count = 0;
    if (ok) {
      for (int j = 1; j <= N && ok; ++j) {
        int now = A[j] % i;
        if (F[now] == 0)
          F[now] = 1;
        else {
          ++count;
          if (count > K) break;
        }
      }
      for (int j = 1; j <= N; ++j) F[A[j] % i] = 0;
    }
    if (ok && count <= K) {
      cout << i << '\n';
      break;
    }
  }
}

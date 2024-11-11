#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    long long S;
    cin >> N >> S;
    long long R[N];
    pair<long long, long long> LR[N];
    for (int i = 0; i < N; ++i) {
      long long l, r;
      cin >> l >> r;
      R[i] = r;
      LR[i] = {l, r};
    }
    sort(R, R + N);
    sort(LR, LR + N);
    long long result = 0;
    for (long long b = R[N / 2]; b >= 1; b /= 2) {
      while (result + b <= R[N / 2]) {
        long long spent = 0;
        int over = 0;
        for (int i = N - 1; i >= 0; --i) {
          long long l, r;
          tie(l, r) = LR[i];
          if (over < (N + 1) / 2 && result + b <= r) {
            ++over;
            spent += max(l, result + b);
          } else {
            spent += l;
          }
        }
        if (spent > S) break;
        result += b;
      }
    }
    cout << result << '\n';
  }
}

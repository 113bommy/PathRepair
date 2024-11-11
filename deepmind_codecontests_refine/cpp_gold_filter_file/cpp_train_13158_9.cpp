#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
typedef long long l_N[maxN];
int N, K;
l_N A, S, Fx, Gx;
long long ans;
long long sum(const int i) { return S[i + K - 1] - S[i - 1]; }
int main() {
  cin >> N >> K;
  for (int i = 0; i < N; i++) cin >> A[i + 1];
  for (int i = 1; i <= N; i++) S[i] = S[i - 1] + A[i];
  Fx[N - K + 1] = N - K + 1;
  for (int i = N - K; i; i--)
    Fx[i] = (sum(i) >= sum(Fx[i + 1])) ? i : Fx[i + 1];
  for (int i = K; i <= N - K; i++)
    ans = max(ans, S[i] - S[i - K] + sum(Fx[i + 1]));
  for (int i = K; i <= N - K; i++)
    if (ans == S[i] - S[i - K] + sum(Fx[i + 1])) {
      cout << i - K + 1 << ' ' << Fx[i + 1];
      return 0;
    }
}

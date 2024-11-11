#include <bits/stdc++.h>
using namespace std;
int N, M;
pair<long long, char> A[1100100], B[1100100];
char dummy;
long long sol;
namespace StringMatching {
pair<long long, char> str[1100100];
int z[1100100], pi[1100100];
bool ok[1100100];
void zfunction() {
  int L = 0, R = 0;
  int n = N + M - 2;
  for (int i = 0; i <= n; i++) z[i] = 0;
  for (int i = 1; i < n; i++) {
    if (i <= R) z[i] = min(z[i - L], R - i + 1);
    while (i + z[i] < n && str[i + z[i]] == str[z[i]]) z[i]++;
    if (i + z[i] - 1 > R) L = i, R = i + z[i] - 1;
  }
}
template <class T>
void print(T *X, int n) {
  for (int I = 0; I < n; I++) cout << X[I] << " \n"[I + 1 == n];
}
void match() {
  for (int I = 1; I <= M - 2; I++) str[I - 1] = B[I + 1];
  for (int I = 1; I <= N; I++) str[M - 2 + I - 1] = A[I];
  zfunction();
  for (int I = M - 2; I < N + M - 2; I++) {
    if (z[I] >= M - 2) {
      int idx = I - (M - 2);
      ok[idx] = true;
      idx++;
      if (idx > 1 && A[idx - 1].second == B[1].second &&
          A[idx - 1].first >= B[1].first) {
        int lst = idx + M - 2;
        if (lst <= N && A[lst].second == B[M].second &&
            A[lst].first >= B[M].first) {
          sol++;
        }
      }
    }
  }
}
}  // namespace StringMatching
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M;
  for (int I = 1; I <= N; I++) cin >> A[I].first >> dummy >> A[I].second;
  for (int I = 1; I <= M; I++) cin >> B[I].first >> dummy >> B[I].second;
  int tmp = 1;
  for (int I = 2; I <= N; I++) {
    if (A[tmp].second == A[I].second)
      A[tmp].first += A[I].first;
    else
      A[++tmp] = A[I];
  }
  N = tmp;
  tmp = 1;
  for (int I = 2; I <= M; I++) {
    if (B[tmp].second == B[I].second)
      B[tmp].first += B[I].first;
    else
      B[++tmp] = B[I];
  }
  M = tmp;
  if (M == 1) {
    for (int I = 1; I <= N; I++)
      if (A[I].second == B[1].second)
        sol += max(0ll, A[I].first - B[1].first + 1);
    cout << sol << endl;
    return 0;
  }
  if (M == 2) {
    for (int I = 1; I <= N - 1; I++)
      if (A[I].second == B[1].second && A[I + 1].second == B[2].second)
        sol += A[I].first >= B[1].first && A[I + 1].first >= B[2].first;
    cout << sol << endl;
    return 0;
  }
  StringMatching::match();
  cout << sol << endl;
}

#include <bits/stdc++.h>
using namespace std;
int A[200000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  N *= 2;
  for (int i = 0; i < N; ++i) A[i] = i + 1;
  for (int i = 0; i <= K; i += 2) swap(A[i], A[i ^ 1]);
  for (int i = 0; i < N; ++i) cout << A[i] << " \n"[i == N - 1];
}

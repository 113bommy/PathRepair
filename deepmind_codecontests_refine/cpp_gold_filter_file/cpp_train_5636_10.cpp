#include <bits/stdc++.h>
using namespace std;
long long A[1000001], L[10], S[10], res = 0;
int d(int a) {
  if (a % 9 == 0) return 9;
  return a % 9;
}
int main(int argc, char *argv[]) {
  int N, i, j;
  cin >> N;
  for (i = 1; i <= N; i++)
    for (j = 1; i * j <= N; j++) A[i * j]++;
  for (i = 1; i <= 9; i++) L[i] = (N - i + 9) / 9;
  for (i = 1; i <= 9; i++)
    for (j = 1; j <= 9; j++) S[d(i * j)] += L[i] * L[j];
  for (i = 1; i <= N; i++) res -= A[i];
  for (i = 1; i <= 9; i++) res += S[i] * L[i];
  cout << res << endl;
  return 0;
}

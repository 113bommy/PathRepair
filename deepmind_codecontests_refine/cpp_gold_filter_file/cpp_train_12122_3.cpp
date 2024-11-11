#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int N, M;
  cin >> N >> M;
  long long int A[M + N], input[M + N];
  memset(A, 0, sizeof(A));
  for (int i = 1; i <= M; i++) cin >> input[i];
  for (int i = 1; i <= M; i++)
    for (int j = input[i]; j <= N; j++)
      if (!A[j]) A[j] = input[i];
  for (int i = 1; i <= N; i++) cout << A[i] << " ";
  return 0;
}

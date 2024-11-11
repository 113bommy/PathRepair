#include <bits/stdc++.h>
using namespace std;
vector<int> S;
int A[100010];
int B[100010];
int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  for (int j = 0; j < M; j++) scanf("%d", &B[j]);
  sort(A, A + N);
  sort(B, B + M);
  for (int i = 0, j = M - 1; (i < N) && (j >= 0); i++, j--) {
    if (A[i] < B[j]) {
      S.push_back(A[i]);
      S.push_back(B[j]);
    } else
      break;
  }
  sort(S.begin(), S.end());
  int Size = S.size();
  if (Size != 0) {
    int Mid = S[Size / 2];
    long long Sum = 0;
    for (int i = 0; i < Size; i++) Sum += abs(S[i] - Mid);
    cout << Sum << endl;
  } else
    cout << "0" << endl;
  return 0;
}

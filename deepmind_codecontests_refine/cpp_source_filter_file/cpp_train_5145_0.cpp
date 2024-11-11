#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500050;
int A[MAXN];
int Ans, N;
bool Check(int m) {
  int j;
  for (int i = N - m; i < N; i++) {
    j = i - (N - m);
    if (A[i] < A[j] * 2) return false;
  }
  return true;
}
int BinarySearch(int l, int r) {
  if (l == r) return l;
  int m = (l + r + 1) >> 1;
  if (Check(m))
    return BinarySearch(m, r);
  else
    return BinarySearch(l, m - 1);
}
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  Ans = BinarySearch(0, N - (N - 1) / 2);
  cout << N - Ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int gi() {
  int res = 0, w = 1;
  char ch = getchar();
  while (ch != '-' && !isdigit(ch)) ch = getchar();
  if (ch == '-') w = -1, ch = getchar();
  while (isdigit(ch)) res = res * 10 + ch - '0', ch = getchar();
  return res * w;
}
const int MAX_N = 1005;
int N, M, A[MAX_N], B[MAX_N];
bitset<500 * MAX_N> bit[505];
bool solve(int *A, vector<int> &S, vector<int> &T) {
  int sum = 0;
  for (int i = 1; i <= N; i++)
    bit[i] = bit[i - 1] | (bit[i - 1] << A[i]), sum += A[i];
  if ((sum & 1) || (!bit[N][sum >> 1])) return 0;
  for (int i = N, j = sum >> 1; i; i--) {
    if (bit[i - 1][j])
      S.push_back(A[i]);
    else
      j -= A[i], T.push_back(A[i]);
  }
  return 1;
}
int main() {
  int T = gi();
  bit[0][0] = 1;
  while (T--) {
    N = gi();
    for (int i = 1; i <= N; i++) A[i] = gi();
    M = gi();
    for (int i = 1; i <= M; i++) B[i] = gi();
    if (N != M) {
      puts("No");
      continue;
    }
    vector<int> Al, Ar, Bu, Bd;
    if (!solve(A, Al, Ar) || !solve(B, Bu, Bd)) {
      puts("No");
      continue;
    }
    if (Al.size() < Ar.size()) swap(Al, Ar);
    if (Bu.size() < Bd.size()) swap(Bu, Bd);
    sort(Al.begin(), Al.end(), greater<int>());
    sort(Ar.begin(), Ar.end(), greater<int>());
    sort(Bu.begin(), Bu.end());
    sort(Bd.begin(), Bd.end());
    vector<int> AA = Al, BB = Bu;
    for (int i : Ar) AA.push_back(-i);
    for (int i : Bd) BB.push_back(-i);
    puts("Yes");
    for (int i = 0, x = 0, y = 0; i < N; i++) {
      x += AA[i];
      printf("%d %d\n", x, y);
      y += BB[i];
      printf("%d %d\n", x, y);
    }
  }
  return 0;
}

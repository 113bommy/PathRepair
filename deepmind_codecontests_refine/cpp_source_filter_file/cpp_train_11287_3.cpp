#include <bits/stdc++.h>
using namespace std;
void _fill_int(int* p, int val, int rep) {
  int i;
  for (i = 0; i < rep; i++) p[i] = val;
}
signed long long GETi() {
  signed long long i;
  scanf("%lld", &i);
  return i;
}
int N, A[100001];
void solve() {
  int f, i, j, k, l, x, y;
  cin >> N;
  for (i = 0; i < N; i++) cin >> A[i];
  sort(A, A + N);
  if (N == 1) return (void)printf("-1\n");
  if (A[0] == A[N - 1]) (void)printf("1\n%d\n", A[0]);
  if (N == 2 && (A[1] - A[0]) % 2 == 0)
    return (void)printf("3\n%d %d %d\n", A[0] - (A[1] - A[0]),
                        A[0] + (A[1] - A[0]) / 2, A[1] + (A[1] - A[0]));
  int mi = A[1] - A[0];
  for (i = 0; i < N - 1; i++) mi = min(mi, A[i + 1] - A[i]);
  x = -1;
  for (i = 0; i < N - 1; i++) {
    if (A[i + 1] - A[i] == mi)
      continue;
    else if (A[i + 1] - A[i] == 2 * mi && x == -1)
      x = i;
    else
      return (void)printf("0\n");
  }
  if (x == -1)
    (void)printf("2\n%d %d\n", A[0] - mi, A[N - 1] + mi);
  else
    (void)printf("1\n%d\n", A[x] + mi);
}
int main(int argc, char** argv) {
  string s;
  if (argc == 1) ios::sync_with_stdio(false);
  for (int i = 1; i < argc; i++) s += argv[i], s += '\n';
  for (int i = s.size() - 1; i >= 0; i--) ungetc(s[i], stdin);
  solve();
  return 0;
}

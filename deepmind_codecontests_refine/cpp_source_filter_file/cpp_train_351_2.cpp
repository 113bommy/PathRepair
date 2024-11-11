#include <bits/stdc++.h>
using namespace std;
const int Nmax = 100010;
long long N, A[Nmax];
bool cmp(int a, int b) { return a > b; }
bool good(long long x) {
  long long tot = 0;
  for (int i = 1; i <= N; ++i) tot += x - A[i];
  if (tot >= A[1]) return 1;
  return 0;
}
long long BS(long long st, long long dr) {
  if (st == dr) return st;
  long long mid = (st + dr) / 2;
  if (good(mid)) return BS(st, mid);
  return BS(mid + 1, dr);
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> A[i];
  sort(A + 1, A + N + 1, cmp);
  cout << BS(A[1], 1LL << 40) << '\n';
}

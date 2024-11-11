#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
long long n;
int k;
int a[100];
int b[100][MAXN];
inline long long get_ans(int i, long long N) {
  if (N == 0) return 0;
  if (i >= k) return N;
  if (N < MAXN && b[i][N] != -1) return b[i][N];
  long long res = get_ans(i + 1, N) - get_ans(i + 1, N / a[i]);
  if (N < MAXN) b[i][N] = res;
  return res;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) cin >> a[i];
  sort(a, a + k, greater<int>());
  memset(b, -1, sizeof b);
  cout << get_ans(0, n) << endl;
}

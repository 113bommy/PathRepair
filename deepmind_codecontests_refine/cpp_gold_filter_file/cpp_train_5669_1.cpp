#include <bits/stdc++.h>
using namespace std;
long long n, a[5500];
ifstream fin("input.txt");
long long solve(long long l, long long r, long long h) {
  if (l >= r) return 0;
  if (l == r - 1) return 1;
  long long ans = 0, mini = (long long)1e15, last = l;
  for (long long i = l; i < r; i++) mini = min(mini, a[i]);
  for (long long i = l; i < r; i++)
    if (a[i] == mini) {
      ans += solve(last, i, mini), last = i + 1;
    }
  ans += solve(last, r, mini);
  return min(ans + mini - h, r - l);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  cout << solve(0, n, 0);
  return 0;
}

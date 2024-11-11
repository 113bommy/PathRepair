#include <bits/stdc++.h>
using namespace std;
int N;
long long arr[40], M, sol;
set<long long> S;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    arr[i] %= M;
  }
  int ma = (N + 1) / 2, ma2 = N / 2;
  int lim = (1 << ma);
  long long sum;
  for (int i = 0; i < lim; i++) {
    sum = 0;
    for (int j = 0; j < ma; j++)
      if (i & (1 << j)) sum = (sum + arr[j]) % M;
    S.insert(sum);
  }
  lim = (1 << ma2);
  set<long long>::iterator it = S.end();
  it--;
  long long fin = *it, po, sol = 0;
  for (int i = 0; i < lim; i++) {
    sum = 0;
    for (int j = 0; j < ma2; j++)
      if (i & (1 << j)) sum = (sum + arr[ma + j]) % M;
    it = S.upper_bound(M - 1LL - sum);
    if (it != S.begin()) it--;
    po = *it;
    sol = max({(po + sum) % M, sol, (fin + sum) % M});
  }
  sol = max(fin, sol);
  cout << sol << "\n";
  return 0;
}

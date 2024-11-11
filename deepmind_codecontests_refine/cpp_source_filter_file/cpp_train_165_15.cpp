#include <bits/stdc++.h>
using namespace std;
int A[200010];
set<int> proc;
int N;
int btchng[200010][31][2];
long long calc(int idx) {
  int val = A[idx];
  auto lm = proc.lower_bound(idx);
  int lmr = *lm;
  lm--;
  int lml = *lm;
  int fidx = lmr, pidx = lml;
  for (int j = 0; j < 31; j++)
    if (!(val & (1 << j))) {
      fidx = min(fidx, btchng[idx][j][1]);
      pidx = max(pidx, btchng[idx][j][0]);
    }
  int selr = lmr - fidx, sell = pidx - lml;
  proc.insert(idx);
  return (idx - lml) * selr + (lmr - idx) * sell - sell * selr;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  for (int j = 0; j < 31; j++) btchng[0][j][0] = -1;
  for (int j = 0; j < 31; j++) btchng[N + 1][j][1] = N + 1;
  for (int i = 1; i <= N; i++)
    for (int j = 0; j < 31; j++)
      btchng[i][j][0] = (A[i] & (1 << j)) ? i : btchng[i - 1][j][0];
  for (int i = N; i >= 1; i--)
    for (int j = 0; j < 31; j++)
      btchng[i][j][1] = (A[i] & (1 << j)) ? i : btchng[i + 1][j][1];
  proc.insert(0);
  proc.insert(N + 1);
  vector<int> vals(N);
  for (int i = 0; i < N; i++) vals[i] = i + 1;
  sort(vals.rbegin(), vals.rend(),
       [](int lhs, int rhs) { return A[lhs] < A[rhs]; });
  long long total = 0;
  for (auto x : vals) total += calc(x);
  cout << total << endl;
}

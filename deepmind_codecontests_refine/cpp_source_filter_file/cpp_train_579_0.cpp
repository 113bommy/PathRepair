#include <bits/stdc++.h>
using namespace std;
signed long long A, B, H, W;
int N;
signed long long C[101010];
void solve() {
  int i, j, k, l, r, x, y;
  string s;
  cin >> A >> B >> H >> W >> N;
  for (i = 0; i < (N); i++) cin >> C[i];
  sort(C, C + N);
  reverse(C, C + N);
  N = min(35, N);
  if (max(A, B) >= max(H, W) && min(A, B) >= min(H, W))
    return (void)printf("0\n");
  set<signed long long> S;
  S.insert(1);
  signed long long tot = 1;
  for (i = 0; i < (N); i++) {
    set<signed long long> S2 = S;
    if (tot * C[i] / C[i] != tot) break;
    tot *= C[i];
    for (auto& r : S2) S.insert(min(r * C[i], 100000LL));
    int ok = 0;
    for (auto& r : S) {
      if (r * H >= A && (tot / r) * W >= B) ok = 1;
      if (r * H >= B && (tot / r) * W >= A) ok = 1;
    }
    if (ok) break;
  }
  if (i == N)
    cout << -1 << endl;
  else
    cout << i + 1 << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  solve();
  return 0;
}

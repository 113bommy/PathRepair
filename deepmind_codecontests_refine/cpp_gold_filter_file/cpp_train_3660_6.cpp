#include <bits/stdc++.h>
using namespace std;
int N;
signed long long X[2020], Y[2020];
string S;
int vis[2020];
signed long long lef(int a, int b, int c) {
  return (X[b] - X[a]) * (Y[c] - Y[a]) > (Y[b] - Y[a]) * (X[c] - X[a]);
}
void solve() {
  int i, j, k, l, r, x, y;
  cin >> N;
  for (i = 0; i < (N); i++) cin >> X[i] >> Y[i];
  cin >> S;
  int s = 0;
  for (i = 0; i < (N); i++)
    if (X[i] < X[s]) s = i;
  vector<int> V;
  V.push_back(s);
  vis[s] = 1;
  for (auto& c : S) {
    int cur = V.back();
    int cand = -1;
    for (i = 0; i < (N); i++)
      if (vis[i] == 0) {
        if (cand == -1) {
          cand = i;
        } else {
          if (lef(cur, cand, i) == (c == 'R')) cand = i;
        }
      }
    vis[cand] = 1;
    V.push_back(cand);
  }
  for (i = 0; i < (N); i++)
    if (vis[i] == 0) V.push_back(i);
  for (auto& v : V) cout << (v + 1) << " ";
  cout << endl;
}
int main(int argc, char** argv) {
  string s;
  int i;
  if (argc == 1) ios::sync_with_stdio(false), cin.tie(0);
  for (i = 0; i < (argc - 1); i++) s += argv[i + 1], s += '\n';
  for (i = 0; i < (s.size()); i++) ungetc(s[s.size() - 1 - i], stdin);
  cout.tie(0);
  solve();
  return 0;
}

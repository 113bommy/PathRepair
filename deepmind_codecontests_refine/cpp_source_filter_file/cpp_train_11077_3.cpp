#include <bits/stdc++.h>
using namespace std;
int const OO = (1 << 28);
int cnt[5003];
vector<pair<int, pair<int, int> > > X;
void solve(int inc, char dir, int S, int F) {
  int idx = 0;
  int t = 0;
  while (++t && S != F) {
    if (idx >= X.size() || t != X[idx].first) {
      S += inc;
      cout << dir;
    } else {
      if ((S < X[idx].second.first || S > X[idx].second.second) &&
          (S + 1 < X[idx].second.first || S + 1 > X[idx].second.second)) {
        S += inc;
        cout << dir;
      } else
        cout << "X";
      idx++;
    }
  }
  cout << endl;
}
int main() {
  int N, M, S, F;
  cin >> N >> M >> S >> F;
  for (int i = 0; i < M; ++i) {
    int t, l, r;
    cin >> t >> l >> r;
    X.push_back(make_pair(t, make_pair(l, r)));
  }
  if (S < F) {
    solve(1, 'R', S, F);
  } else {
    solve(-1, 'L', S, F);
  }
}

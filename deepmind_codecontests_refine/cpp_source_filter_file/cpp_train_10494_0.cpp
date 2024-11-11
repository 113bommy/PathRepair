#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

bool solve() {
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  string S; cin >> S;
  rep(i, B, D) if(S[i-1] == '#' && S[i] == '#') return false;
  rep(i, A, C) if(S[i-1] == '#' && S[i] == '#') return false;
  if(C < D) return true;
  int cnt = 0;
  rep(i, B-2, D+1) {
    if(S[i] != '#') cnt++;
    else cnt = 0;
    if(cnt >= 3) return true;
  }
  else return false;
}

int main() {
  cout << (solve() ? "Yes" : "No") << endl;
  return 0;
}

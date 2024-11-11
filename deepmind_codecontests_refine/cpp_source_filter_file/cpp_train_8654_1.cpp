#include <bits/stdc++.h>
using namespace std;
long long N, S[100100], Q;
const long long INF = (long long)1e18 * 7 + 10;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N;
  for (long long i = 0; i < N; i++) {
    cin >> S[i];
  }
  sort(S, S + N);
  N = unique(S, S + N) - S;
  S[N] = INF;
  for (long long i = 0; i < N; i++) {
    S[i] = S[i + 1] - S[i];
  }
  S[N - 1] = INF;
  sort(S, S + N);
  map<long long, pair<long long, long long> > ans;
  ans[S[0]] =
      pair<long long, long long>(0LL + (S[0] - 0LL) * (N - 0LL), N - 0LL);
  for (long long i = 1; i < N; i++) {
    if (ans.count(S[i]) != 0) {
      ans[S[i]] = pair<long long, long long>(
          ans[S[i - 1]].first + (S[i] - S[i - 1]) * (N - i), N - i);
    }
  }
  cin >> Q;
  vector<long long> jawab;
  while (Q--) {
    long long L, R;
    cin >> L >> R;
    R -= L - 1;
    map<long long, pair<long long, long long> >::iterator it =
        ans.lower_bound(R);
    jawab.push_back((it->second).first -
                    ((long long)it->first - R) * (it->second).second);
  }
  for (long long i = 0; i < (long long)jawab.size(); i++) {
    cout << jawab[i];
    cout << (i != (long long)jawab.size() - 1 ? " " : "\n");
  }
  return 0;
}

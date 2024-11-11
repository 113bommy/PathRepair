#include <bits/stdc++.h>
using namespace std;
long long D, V, N, curr, sol;
pair<long long, long long> A[200100];
set<pair<long long, long long> > S;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> D >> V >> N;
  N++;
  A[1] = {0, 0};
  for (int I = 2; I <= N; I++) cin >> A[I].first >> A[I].second;
  sort(A + 1, A + 1 + N);
  A[++N] = {D, 0};
  A[N + 1] = {D, 0};
  for (int I = 1; I <= N; I++) {
    while (!S.empty() && S.rbegin()->first >= A[I].second) {
      curr -= S.rbegin()->second;
      S.erase(S.find(*S.rbegin()));
    }
    long long r = A[I + 1].first - A[I].first;
    long long top = V - r;
    if (r > V) {
      cout << -1 << endl;
      return 0;
    }
    while (!S.empty() && S.begin()->second < r) {
      r -= S.begin()->second;
      sol += S.begin()->second * S.begin()->first;
      curr -= S.begin()->second;
      S.erase(S.begin());
    }
    if (!S.empty()) {
      sol += r * S.begin()->first;
      pair<long long, long long> tmp = {S.begin()->first,
                                        S.begin()->second - r};
      curr -= S.begin()->second;
      curr += tmp.second;
      S.erase(S.begin());
      S.insert(tmp);
      r = 0;
    }
    sol += r * A[I].second;
    S.insert({A[I].second, top - curr});
    curr = top;
  }
  cout << sol << endl;
}

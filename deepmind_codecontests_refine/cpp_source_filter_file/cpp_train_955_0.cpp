#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
long long Q, N, R;
vector<long long> V;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> Q;
  for (long long q = 0; q < Q; q++) {
    cin >> N >> R;
    V.resize(N, 0);
    for (long long i = 0; i < N; i++) cin >> V[i];
    sort(V.begin(), V.end(), greater<long long>());
    V.erase(unique(V.begin(), V.end()), V.end());
    long long away = 0;
    long long ans = 0;
    for (long long i : V) {
      if (i - away > 0) ans++;
      away += R;
    }
    cout << ans;
  }
  return 0;
}

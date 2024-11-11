#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = (1LL << 62) - 1 + (1LL << 62);
const double PI = acos(-1.0);
const bool LOG = false;
void Log() {
  if (LOG) cerr << "\n\n";
}
template <class T, class... S>
void Log(T t, S... s) {
  if (LOG) cerr << t << "\t", Log(s...);
}
template <class T>
using min_queue = priority_queue<T, vector<T>, greater<T>>;
const int maxn = 2e5 + 10;
int N, X[maxn], Y[maxn], H[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr << boolalpha;
  (cout << fixed).precision(20);
  cin >> N;
  for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
  for (int i = 0; i < N; i++) Y[i] += X[i];
  H[0] = Y[0];
  for (int i = 1; i < N; i++) H[i] = min(H[i - 1] + 1, Y[i]);
  for (int i = N - 2; i >= 0; i--) H[i] = min(H[i + 1] + 1, H[i]);
  for (int i = 0; i < N; i++) {
    if (H[i] < X[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  long long sumlawns = 0LL;
  for (int i = 0; i < N; i++) {
    sumlawns += H[i] - X[i];
  }
  cout << sumlawns << endl;
  for (int i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << H[i];
  }
  cout << endl;
  return 0;
}

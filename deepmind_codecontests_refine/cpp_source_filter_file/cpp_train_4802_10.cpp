#include <bits/stdc++.h>
using namespace std;
const long long int N = 200009;
const long long int mod = 1000000007;
vector<vector<long long int>> divi(N, vector<long long int>(0));
void pre() {
  for (long long int i = 1; i < N; i++) {
    for (long long int j = i; j < N; j += i) {
      divi[j].push_back(i);
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin.exceptions(cin.failbit);
  ;
  pre();
  long long int t = 1;
  for (long long int T = 1; T < (t + 1); ++T) {
    long long int n, a, b;
    cin >> n;
    vector<long long int> x(n + 1, 0), sq(n + 1, 0);
    for (long long int i = 2; i <= (n); i += 2) {
      cin >> x[i];
      for (auto& it : divi[x[i]]) {
        a = it, b = x[i] / it;
        if (a >= b) break;
        if ((a % 2) != (b % 2)) continue;
        long long int s1 = (b - a) / 2;
        if ((s1 * s1) > sq[i - 2]) {
          x[i - 1] = (s1 * s1) - sq[i - 2];
          sq[i - 1] = s1 * s1;
          sq[i] = ((b + a) / 2) * ((b + a) / 2);
        }
      }
      if (x[i - 1] == 0) {
        cout << "NO\n";
        return 0;
      }
    }
    cout << "YES\n";
    for (long long int i = 1; i <= (n); i += 1) {
      cout << x[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}

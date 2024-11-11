#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
const int MOD = 1000000007;
unordered_map<int, vector<int>> busses;
vector<int> stops;
long long numWays[N + 1];
long long add(long long a, long long b) { return (a + b) % MOD; }
long long sub(long long a, long long b) {
  long long result = (a - b) % MOD;
  while (result < 0) result += MOD;
  return result;
}
void solve() {
  int n, m;
  cin >> m >> n;
  stops.push_back(0);
  for (int i = 0; i < n; i++) {
    int s, t;
    cin >> s >> t;
    if (busses[t].size() == 0) {
      stops.push_back(t);
    }
    busses[t].push_back(s);
  }
  sort(stops.begin(), stops.end());
  numWays[0] = 1;
  for (int i = 1; i < stops.size(); i++) {
    for (int start : busses[stops[i]]) {
      int startInd =
          lower_bound(stops.begin(), stops.end(), start) - stops.begin();
      long long sum = add(numWays[i], numWays[i - 1]);
      numWays[i] = sub(sum, (startInd > 0 ? numWays[startInd - 1] : 0));
    }
    numWays[i] = add(numWays[i], numWays[i - 1]);
  }
  if (stops[stops.size() - 1] != m) {
    cout << 0;
  } else {
    cout << sub(numWays[stops.size() - 1], numWays[stops.size() - 2]);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
  getchar();
  getchar();
}

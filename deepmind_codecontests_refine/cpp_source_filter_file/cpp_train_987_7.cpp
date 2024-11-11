#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int n, d, a, b;
  cin >> n >> d;
  vector<pair<int, int> > V;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    V.push_back(pair<int, int>(a, b));
  }
  sort(V.begin(), V.end());
  long long int sum = 0, r_sum = 0;
  for (a = 0, b = 0; a < n; a++) {
    while (V[a].first + d >= V[b].first && b <= n) r_sum += V[b].second, b++;
    sum = max(sum, r_sum);
    r_sum -= V[a].second;
  }
  cout << sum << "\n";
}

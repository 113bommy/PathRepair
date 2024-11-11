#include <bits/stdc++.h>
using namespace std;
int T;
long long N;
int main() {
  cin >> N;
  vector<long long> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  long long res = (v[0]) * (N - v[0] + 1);
  for (int i = 1; i < N; i++) {
    if (v[i] < v[i - 1])
      res += v[i] * (v[i - 1] - v[i]);
    else
      res += (N + 1 - v[i]) * (v[i] - v[i - 1]);
  }
  cout << res;
  return 0;
}

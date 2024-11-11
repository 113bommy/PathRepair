#include <bits/stdc++.h>
using namespace std;
long long N, A[200005];
vector<long long> v, v2;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (long long i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 0) {
      v.push_back(i);
      v2.push_back(-i);
    }
  }
  sort(v.begin(), v.end());
  sort(v2.begin(), v2.end());
  for (long long i = 0; i < N; i++) {
    auto it = lower_bound(v.begin(), v.end(), i);
    auto it2 = lower_bound(v2.begin(), v.end(), -i);
    long long best = 1e9;
    if (it != v.end()) {
      best = min(best, abs(*it - i));
    }
    if (it2 != v2.end()) {
      best = min(best, abs(*it2 + i));
    }
    cout << best << " \n"[i == N - 1];
  }
  return 0;
}

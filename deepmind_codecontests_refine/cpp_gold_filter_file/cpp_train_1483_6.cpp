#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
using bigint = long long int;
using vi = vector<int>;
using vll = vector<long long int>;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int N, M;
  cin >> N >> M;
  bigint arr[M + 1], suffix[M + 2];
  for (int i = 1; i <= M; i++) {
    cin >> arr[i];
  }
  suffix[M + 1] = 0;
  for (int i = M; i >= 1; i--) {
    suffix[i] = suffix[i + 1] + arr[i];
    if (i + arr[i] - 1 > N) {
      cout << "-1"
           << "\n";
      return 0;
    }
  }
  if (suffix[1] < N) {
    cout << "-1"
         << "\n";
    return 0;
  }
  for (bigint i = 1; i <= M; i++) {
    cout << max(i, N - suffix[i] + 1) << " ";
  }
  cout << "\n";
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<long long> V(N);
  for (long long &v : V) cin >> v;
  sort(V.begin(), V.end());
  long long an = 1000000000000000LL;
  long long st = 0, d = 0;
  for (int i = 0; i <= 5; ++i) {
    vector<long long> A = V;
    long long mi = A[0], ma = A[0];
    for (int j = 0; j < N; ++j) {
      A[j] -= i * j;
      mi = min(mi, A[j]);
      ma = max(ma, A[j]);
    }
    long long t = (ma - mi + 1) / 2;
    if (an > t) {
      an = t;
      st = (ma + mi) / 2;
      d = i;
    }
  }
  cout << an << endl;
  cout << st << " " << d << endl;
}

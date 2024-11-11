#include <bits/stdc++.h>
using namespace std;
int main() {
  long N;
  cin >> N;
  vector<pair<long long, long> > A(N);
  vector<bool> Used(N, false);
  for (pair<long long, long> &X : A) cin >> X.first;
  for (pair<long long, long> &X : A) cin >> X.second;
  sort(A.begin(), A.end());
  long long Answer = 0;
  long l = 0, r = 0;
  while (l < N) {
    r = l;
    while ((r < N) && (A[r].first == A[l].first)) ++r;
    if (r > l + 1)
      for (long i = 0; i < r; ++i)
        if (!Used[i] && ((A[i].first | A[l].first) == A[l].first)) {
          Answer += A[i].second;
          Used[i] = true;
        }
    l = r;
  }
  cout << Answer << endl;
}

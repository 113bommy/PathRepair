#include <bits/stdc++.h>
using namespace std;
vector<int> A;
int D[300];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<pair<int, int> > A(n);
  memset(D, 0, sizeof(D));
  int C = 0;
  for (int i = 0; i < n; ++i) cin >> A[i].first;
  for (int i = 0; i < n; ++i)
    cin >> A[i].second, D[A[i].second]++, C += A[i].second;
  sort(A.rbegin(), A.rend());
  int best = 1e9, P = 0, p = 0;
  for (int i = 0; i < n; ++i) {
    int j = i, cnt = 0;
    while (j < n && A[j].first == A[i].first) {
      cnt++;
      C -= A[j].second;
      p += A[j].second;
      D[A[j].second]--;
      j++;
    }
    cnt--;
    int V = 0;
    for (int i = 200; i >= 1; i--)
      if (D[i] && cnt) {
        int q = min(cnt, D[i]);
        V += q * i;
        cnt -= q;
      }
    best = min(best, P + C - V);
    i = j - 1;
    P += p;
  }
  cout << best << "\n";
  return 0;
}

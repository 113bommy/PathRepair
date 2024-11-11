#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int m;
  cin >> m;
  unsigned long long int A[m], Ap[m];
  unsigned long long int B[m];
  map<unsigned long long int, vector<unsigned long long int> > mp;
  for (long long int i = 0; i < m; i++) {
    cin >> B[i];
  }
  for (long long int i = 0; i < m; i++) {
    cin >> A[i];
    Ap[i] = A[i];
  }
  sort(Ap, Ap + m);
  sort(B, B + m);
  for (int i = 0; i < m; i++) {
    mp[Ap[i]].push_back(B[m - 1 - i]);
  }
  for (long long int i = 0; i < m; i++) {
    cout << mp[A[i]].back() << " ";
    mp[A[i]].pop_back();
  }
}
int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}

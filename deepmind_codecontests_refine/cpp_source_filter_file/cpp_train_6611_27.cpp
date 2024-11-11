#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int A[100010], B[100010], C[100010];
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (!mp[A[i]]) {
      mp[A[i]] = i + 1;
    } else {
      mp[A[i]] = -1;
    }
  }
  int amb = 0, imp = 0;
  ;
  for (int i = 0; i < m; i++) cin >> B[i];
  for (int i = 0; i < m; i++) {
    if (mp[B[i]] == -1)
      amb = 1;
    else if (mp[B[i]] == 0) {
      cout << "Impossible\n";
      imp = 1;
      return 0;
    } else
      C[i] = mp[B[i]];
  }
  if (amb)
    cout << "Ambiguity\n";
  else {
    cout << "Possible\n";
    for (int i = 0; i < n; i++) cout << C[i] << " ";
  }
}

#include <bits/stdc++.h>
using namespace std;
int n, m;
int a, in, A[200010], B[200010];
map<int, int> M;
pair<int, int> ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    M[a]++;
  }
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> A[i];
  for (int i = 1; i <= m; i++) cin >> B[i];
  for (int i = 1; i <= m; i++)
    if (ans <= make_pair(M[A[i]], M[B[i]])) ans = {M[A[i]], M[B[i]]}, in = i;
  cout << in;
}

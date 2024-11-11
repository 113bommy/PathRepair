#include <bits/stdc++.h>
using namespace std;
using namespace std;
int mat[3003];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, v;
  cin >> n >> v;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    mat[a] += b;
  }
  int rem = 0;
  int res = 0;
  for (int i = 0; i <= 3000; i++) {
    if (rem > 0) res += min(rem, v);
    if (v > min(rem, v) && mat[i] > 0) res += min(v - min(rem, v), mat[i]);
    rem = mat[i] - min(v - min(rem, v), mat[i]);
  }
  cout << res << endl;
}

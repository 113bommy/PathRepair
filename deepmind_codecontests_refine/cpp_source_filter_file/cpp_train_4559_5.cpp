#include <bits/stdc++.h>
using namespace std;
int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> a(A), b(B);
  for (int &v : a) cin >> v;
  for (int &v : b) cin >> v;
  
  int ans = (*min_element(A.begin(), A.end()))+(*min_element(B.begin(), B.end()));
  while (M--) {
   int x, y, c;
    cin >> x >> y >> c;
    --x, --y;
    ans = min(ans, a[x]+b[y]-c);
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, A[100000] = {}, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v;
    --u;
    --v;
    ++A[u];
    ++A[v];
  }
  int ones = count(A, A + n, 1);
  int twos = count(A, A + n, 2);
  int star = count(A, A + n, n - 1);
  if (ones == 2 && twos == n - 2)
    cout << "bus topology";
  else if (twos == n)
    cout << "ring topology";
  else if (ones == n - 1 && star == 1)
    cout << "star topology";
  else
    cout << "unknown topology";
}

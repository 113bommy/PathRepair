#include <bits/stdc++.h>
const long long oo = 1e9;
int dx[] = {-1, 1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, -1, 1};
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  int n, a[1005];
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] == 1)
    cout << -1 << endl;
  else
    cout << a[0] - 1 << endl;
}

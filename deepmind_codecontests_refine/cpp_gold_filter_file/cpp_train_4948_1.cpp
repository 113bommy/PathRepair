#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(2e5 + 7);
int n, a[MAXN], b[MAXN];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  int pos = 0, pos2 = 0;
  if (a[pos] == 0) pos++;
  for (int i = 0; i < n; i++)
    if (b[i] == a[pos]) pos2 = i;
  for (int i = 0; i < n - 1; i++) {
    if (b[pos2] != a[pos]) {
      cout << "NO";
      return 0;
    }
    pos2 = (pos2 + 1) % n;
    pos = (pos + 1) % n;
    if (b[pos2] == 0) pos2 = (pos2 + 1) % n;
    if (a[pos] == 0) pos = (pos + 1) % n;
  }
  cout << "YES";
  return 0;
}

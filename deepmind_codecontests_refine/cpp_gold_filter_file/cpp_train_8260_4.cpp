#include <bits/stdc++.h>
using namespace std;
const int INF = 2000000000;
const double EPS = 1e-9;
int mods(int a, int b) { return (b + (a % b)) % b; }
int n, cur, a[100005];
long long ans;
bool visited[1048580];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cur = a[i];
    if (!visited[cur]) {
      ans++;
      visited[cur] = 1;
    }
    for (int j = i + 1; j <= i + 80 && j < n; j++) {
      cur |= a[j];
      if (!visited[cur]) {
        visited[cur] = 1;
        ans++;
      }
      if (cur == a[j]) break;
    }
  }
  cout << ans << '\n';
  return 0;
}

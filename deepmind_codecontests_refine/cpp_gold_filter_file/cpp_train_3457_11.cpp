#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
using namespace std;
long long int a[5000 + 1], b[5000 + 1], c[5000 + 1];
bool cmp(long long int a, long long int b) { return c[a] > c[b]; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  long long int defend[n + 1];
  for (int i = 1; i <= n; i++) {
    defend[i] = i;
  }
  for (int i = 0; i < m; i++) {
    long long int u, v;
    cin >> u >> v;
    defend[v] = max(u, defend[v]);
  }
  long long int initial = k;
  long long int dif[5002];
  bool possible = true;
  for (int i = 1; i <= n; i++) {
    dif[i] = initial - a[i];
    if (dif[i] < 0) {
      cout << "-1" << endl;
      possible = false;
      break;
    }
    initial += b[i];
  }
  dif[n + 1] = initial;
  if (possible) {
    long long int s[n + 1];
    for (int i = 1; i <= n; i++) {
      s[i] = i;
    }
    sort(s + 1, s + n + 1, cmp);
    long long int answer = 0;
    for (int i = 1; i <= n; i++) {
      bool poss1 = true;
      for (long long int j = defend[s[i]]; j <= n; j++) {
        if (dif[j + 1] == 0) {
          poss1 = false;
        }
      }
      if (poss1) {
        answer = answer + c[s[i]];
        for (long long int j = defend[s[i]]; j <= n; j++) {
          dif[j + 1]--;
        }
      }
    }
    cout << answer << endl;
  }
}

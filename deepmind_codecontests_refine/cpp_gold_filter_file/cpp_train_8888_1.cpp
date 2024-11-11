#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 5;
int a[MAXN], b[MAXN], t[MAXN], n;
int main() {
  cin >> n;
  for (int i = 0, tmp; i < n; i++) {
    cin >> a[i] >> b[i];
    t[b[i]]++;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++)
    if (t[a[i]] == 0 || (t[a[i]] == 1 && a[i] == b[i])) ans++;
  cout << ans << endl;
  return 0;
}

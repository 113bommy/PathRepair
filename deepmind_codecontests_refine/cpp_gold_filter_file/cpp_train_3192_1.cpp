#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MOD = 1e9 + 7;
char a[MAXN];
int f[MAXN][3];
int n;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++)
    if (a[i] == a[i + 1] && a[i] != '?') {
      cout << "No" << endl;
      exit(0);
    }
  if (a[1] == '?' || a[n] == '?') {
    cout << "Yes" << endl;
    exit(0);
  }
  for (int i = 1; i < n; i++)
    if (a[i] == a[i + 1] && a[i] == '?') {
      cout << "Yes" << endl;
      exit(0);
    }
  for (int i = 2; i < n; i++)
    if (a[i] == '?' && a[i - 1] != '?' && a[i + 1] != '?' &&
        a[i - 1] == a[i + 1]) {
      cout << "Yes" << endl;
      exit(0);
    }
  cout << "No" << endl;
  return 0;
}

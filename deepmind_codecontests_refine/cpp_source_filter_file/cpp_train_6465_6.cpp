#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long double PI = acosl(-1);
const long long inf = 1e15;
const int nmax = 2e3 + 5;
int arr[nmax];
int dif[nmax];
bool posibul[nmax];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    dif[i] = arr[i] - arr[i - 1];
  }
  int ans = 0;
  for (int len = 1; len <= n; len++) {
    bool hobe = true;
    for (int j = len + 1, i = 1; j <= n; j++, i++) {
      if (dif[i] != dif[j]) hobe = false;
      if (i == len) i = 1;
    }
    if (hobe) ans++, posibul[len] = true;
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    if (posibul[i]) cout << i << " ";
  }
}

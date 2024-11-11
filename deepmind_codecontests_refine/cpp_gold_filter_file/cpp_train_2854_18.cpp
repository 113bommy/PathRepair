#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000100;
int n;
int a[MAXN];
bool isok[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> a[i];
  int res = 0;
  int tmp = 0;
  for (int i = 2; i <= (n - 1); ++i) {
    if (a[i - 2] + a[i - 1] == a[i])
      ++tmp;
    else
      tmp = 0;
    res = max(res, tmp);
  }
  cout << min(res + 2, n) << endl;
}

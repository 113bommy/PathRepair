#include <bits/stdc++.h>
using namespace std;
int n;
string a[110], b[110];
map<string, int> dem;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dem[a[i]]++;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    dem[b[i]]--;
  }
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += max(dem[a[i]], 0);
    dem[a[i]] = 0;
  }
  cout << res;
}

#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long large = 2000000000000000000LL;
int main() {
  int n;
  cin >> n;
  vector<int> cnt(n, 0);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    cnt[x]++;
    cnt[y]++;
  }
  int tot = 0;
  for (int i = 0; i < n; i++)
    if (cnt[i] == 0) tot++;
  cout << tot << endl;
  return 0;
}

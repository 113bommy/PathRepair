#include <bits/stdc++.h>
using namespace std;
int a[] = {1, 5, 10, 50};
long long num = 0;
int dfs(int n) {
  map<long long, int> mp;
  mp.clear();
  num = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; i + j <= n; j++) {
      for (int k = 0; i + j + k <= n; k++) {
        int l = i + j * 5 + k * 10 + (n - i - j - k) * 50;
        if (l >= 0 && !mp[l]) {
          num++;
          mp[l] = 1;
        }
      }
    }
  }
  return num;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n <= 20)
    cout << dfs(n) << endl;
  else
    cout << (dfs(20) + (n - 20) * 49) << endl;
  return 0;
}

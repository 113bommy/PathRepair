#include <bits/stdc++.h>
using namespace std;
pair<int, int> arr[(int)(2e5 + 10)];
int w[(int)(2e5 + 10)], K[(int)(2e5 + 10)];
int i, j, k, n, m, x, y, z;
vector<pair<int, int> > ans;
bool islucky(int x) {
  while (x) {
    if (!(x % 10 == 4 or x % 10 == 7)) return 0;
    x /= 10;
  }
  return 1;
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    scanf("%d", &arr[i].first);
    K[i] = i;
    arr[i].second = i;
    w[i] = i;
    if (islucky(arr[i].first)) x = i;
  }
  sort(arr + 1, arr + 1 + n);
  for (i = 1; i <= n; i++) {
    int g = w[arr[i].second], t;
    if (g != i) {
      if (!x) {
        cout << -1 << '\n';
        return 0;
      }
      if (i != w[x]) {
        ans.push_back(make_pair(i, w[x]));
        t = w[x];
        w[x] = i;
        w[K[i]] = t;
        swap(K[i], K[w[x]]);
      }
      if (i != g) {
        ans.push_back(make_pair(i, g));
        w[x] = g;
        w[K[g]] = i;
        swap(K[i], K[g]);
      }
    }
  }
  cout << ans.size() << '\n';
  for (i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
}

#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> dest[n + 1];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    int push = b - a;
    if (b - a < 0) push += n;
    dest[a].push_back(push);
  }
  for (int i = 1; i <= n; i++) {
    sort(dest[i].begin(), dest[i].end());
  }
  for (int i = 1; i <= n; i++) {
    int max_count = 0;
    for (int j = 1; j <= n; j++) {
      int len = dest[j].size();
      max_count = max(max_count, len);
    }
    int total = (max_count - 1) * n;
    int j = i;
    int add = 0;
    for (int k = 0; k < n; k++) {
      int l = j + k;
      if (l > n) {
        l = l - n;
      }
      if (dest[l].size() == max_count) {
        add = max(add, dest[l][0] + k);
      } else if (dest[l].size() == max_count - 1 && dest[l].size() != 0) {
        int diff = i - l;
        if (diff <= 0) {
          diff += n;
        }
        add = max(add, dest[l][0] - diff);
      }
    }
    cout << total + add << " ";
  }
}

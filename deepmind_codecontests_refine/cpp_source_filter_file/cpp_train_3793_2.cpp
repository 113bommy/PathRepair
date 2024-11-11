#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int main() {
  int n, k, a;
  while (cin >> n >> k) {
    vector<int> vec[n];
    int D = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a);
      vec[a].push_back(i);
      D = max(D, a);
    }
    if (vec[0].size() != 1) {
      puts("-1");
      continue;
    }
    bool flag = 1;
    for (int i = 0; i < D; i++) {
      if (i == 0) {
        if (vec[i].size() * k < vec[i + 1].size()) {
          puts("-1");
          flag = 0;
          break;
        }
      } else {
        if (vec[i].size() * (k - 1) < vec[i + 1].size()) {
          puts("-1");
          flag = 0;
          break;
        }
      }
    }
    if (flag == 0) continue;
    printf("%d\n", n - 1);
    int cnt;
    for (int w = 0; w < D; w++) {
      int len = vec[w + 1].size(), i = 0;
      if (w == 0)
        cnt = 0;
      else
        cnt = 1;
      for (int j = 0; j < len;)
        if (cnt < k) {
          printf("%d %d\n", vec[w][i], vec[w + 1][j]);
          j++;
          cnt++;
        } else {
          cnt = 1;
          i++;
        }
    }
  }
  return 0;
}

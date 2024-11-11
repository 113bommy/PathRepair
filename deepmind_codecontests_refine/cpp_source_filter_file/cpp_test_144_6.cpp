#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, m;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> ar(n + 1, 0);
    deque<int> q;
    for (int i = 1; i <= n; i++) {
      ar[i] = i;
      q.push_back(i);
    }
    if (n % m == 0) {
      for (int i = 1; i <= k; i++) {
        int block = n / m, cnt = 0;
        for (int j = 1; j <= n; j++) {
          if (cnt == 0) {
            printf("%d ", block);
          }
          printf("%d ", ar[j]);
          cnt++;
          if (cnt == block) {
            printf("\n");
            cnt = 0;
          }
        }
      }
    } else {
      for (int i = 1; i <= k; i++) {
        int block = n / m, cnt = 0, extra = n % m, j = 1;
        for (j = 1; j <= n; j++) {
          if (extra == 0) break;
          if (cnt == 0) {
            printf("%d ", block + 1);
          }
          printf("%d ", ar[j]);
          cnt++;
          if (cnt == block + 1) {
            extra--;
            cnt = 0;
            printf("\n");
          }
        }
        for (; j <= n; j++) {
          if (cnt == 0) {
            printf("%d ", block);
          }
          printf("%d ", ar[j]);
          cnt++;
          if (cnt == block) {
            printf("\n");
            cnt = 0;
          }
        }
        for (int r = 1; r <= extra; r++) {
          for (int j = 0; j < block; j++) {
            int x = q.back();
            q.pop_back();
            q.push_front(x);
          }
        }
        int idx = 1;
        for (auto p : q) {
          ar[idx++] = p;
        }
      }
    }
    printf("\n");
  }
}

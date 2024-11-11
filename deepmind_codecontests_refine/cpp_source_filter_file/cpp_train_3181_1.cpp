#include <bits/stdc++.h>
int H[100100], dp1[100100][20], dp2[100100][20], last[100100];
int N, K;
void init_dp() {
  for (int j = 0; j < 20; j++) {
    for (int i = 1; i + (1 << j) <= N; i++) {
      dp1[i][j] = (j == 0) ? H[i]
                           : (dp1[i][j - 1] > dp1[i + (1 << (j - 1))][j - 1]
                                  ? dp1[i][j - 1]
                                  : dp1[i + (1 << (j - 1))][j - 1]);
      dp2[i][j] = (j == 0) ? H[i]
                           : (dp2[i][j - 1] > dp2[i + (1 << (j - 1))][j - 1]
                                  ? dp2[i + (1 << (j - 1))][j - 1]
                                  : dp2[i][j - 1]);
    }
  }
}
int query_max(int L, int R) {
  int k = 0;
  while ((1 << (k + 1)) <= R - L + 1) {
    k++;
  }
  return dp1[L][k] > dp1[R - (1 << k) + 1][k] ? dp1[L][k]
                                              : dp1[R - (1 << k) + 1][k];
}
int query_min(int L, int R) {
  int k = 0;
  while ((1 << (k + 1)) <= R - L + 1) {
    k++;
  }
  return dp2[L][k] < dp2[R - (1 << k) + 1][k] ? dp2[L][k]
                                              : dp2[R - (1 << k) + 1][k];
}
int main() {
  while (~scanf("%d%d", &N, &K)) {
    for (int i = 1; i <= N; i++) {
      scanf("%d", &H[i]);
    }
    init_dp();
    for (int i = 1; i <= N; i++) {
      int L = i, R = N;
      while (L < R) {
        int mid = (L + R + 1) / 2;
        int maxx = query_max(i, mid);
        int minx = query_min(i, mid);
        if (maxx - minx > K) {
          R = mid - 1;
        } else {
          L = mid;
        }
      }
      last[i] = L;
    }
    int maxLen = 0;
    for (int i = 1; i <= N; i++) {
      if (maxLen < last[i] - i + 1) {
        maxLen = last[i] - i + 1;
      }
    }
    std::vector<std::pair<int, int> > ans;
    for (int i = 1; i <= N; i++) {
      if (maxLen == last[i] - i + 1) {
        ans.push_back(std::make_pair(i, last[i]));
      }
    }
    std::cout << maxLen << " " << ans.size() << std::endl;
    for (auto v : ans) {
      std::cout << v.first << " " << v.second << std::endl;
    }
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<pair<int, int> > ans;
int main() {
  scanf("%d", &N);
  scanf("%d", &K);
  N -= K;
  int cur = 1, d = 0, mx0 = 0, mx1 = 0;
  queue<pair<int, int> > que;
  for (int i = 0; i < K; i++) que.push(make_pair(1, 0));
  N--;
  while (!que.empty()) {
    pair<int, int> nd = que.front();
    que.pop();
    ans.push_back(make_pair(nd.first, ++cur));
    if (nd.second + 1 >= mx0) {
      mx1 = mx0;
      mx0 = nd.second + 1;
    } else if (nd.second + 1 >= mx1) {
      mx1 = nd.second + 1;
    }
    if (N) {
      N--;
      que.push(make_pair(cur, nd.second + 1));
    }
  }
  printf("%d\n", mx0 + mx1);
  for (int i = 0; i < ans.size(); i++) {
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
}

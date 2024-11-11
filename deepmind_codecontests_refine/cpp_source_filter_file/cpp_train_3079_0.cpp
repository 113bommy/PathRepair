#include <bits/stdc++.h>
using namespace std;
signed main(void) {
  int n, k;
  cin >> n >> k;
  pair<int, int> vec[300006];
  int l, r;
  pair<int, int> num[300006];
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l, &r);
    vec[i] = pair<int, int>(l, r);
    num[i] = pair<int, int>(l, r);
  }
  sort(vec, vec + n);
  int start, end;
  int max = 0;
  priority_queue<int, vector<int>, greater<int> > que;
  for (int i = 0; i < n; i++) {
    que.push(vec[i].second);
    if (que.size() >= k) {
      if (que.size() > k) que.pop();
      if ((que.top() - vec[i].first) + 1 > max) {
        start = vec[i].first;
        end = que.top();
        max = que.top() - vec[i].first + 1;
      }
    }
  }
  if (max == 0) {
    printf("0\n");
    for (int i = 1; i <= k; i++) {
      printf("%d ", i);
    }
  } else {
    cout << max << endl;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (num[i].first <= start && num[i].second >= end && cnt <= k) {
        printf("%d ", i + 1);
        k++;
      }
    }
  }
  return 0;
}

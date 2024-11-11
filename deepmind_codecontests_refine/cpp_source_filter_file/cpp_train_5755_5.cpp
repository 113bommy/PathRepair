#include <bits/stdc++.h>
using namespace std;
int x[200005];
int front[200005];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    map<int, int> count;
    int index = 0;
    for (int i = 1; i <= n; i++) {
      int temp;
      scanf("%d", &temp);
      count[temp]++;
      if (count[temp] == 1) x[index++] = temp;
    }
    for (int i = 1; i <= n; i++) {
      int temp;
      scanf("%d", &temp);
    }
    sort(x, x + index);
    x[index] = 2000000000;
    int left = 0, right = 0;
    int sum = 0;
    vector<pair<int, int>> candidate;
    while (left < index) {
      while (x[right] - x[left] <= k) {
        sum += count[x[right]];
        right++;
      }
      candidate.push_back(make_pair(left, sum));
      sum -= count[x[left]];
      left++;
    }
    left = 0;
    for (int i = 1; i < candidate.size(); i++) {
      front[i] = front[i - 1];
      if (x[candidate[left].first] + k < x[candidate[i].first]) {
        front[i] = max(front[i], candidate[left].second);
        left++;
      }
    }
    int answer = 0;
    for (int i = 0; i < candidate.size(); i++) {
      answer = max(answer, front[i] + candidate[i].second);
    }
    printf("%d\n", answer);
  }
  return 0;
}

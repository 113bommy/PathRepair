#include <bits/stdc++.h>
using namespace std;
void clear(std::queue<long long int> &q) {
  std::queue<long long int> empty;
  std::swap(q, empty);
}
int main() {
  int n, q, lastT = 1, output = 0, query, x;
  scanf("%d%d", &n, &q);
  vector<long long int> unread(n + 1, 0), msgs;
  vector<queue<long long int>> firstUnread(n + 1);
  msgs.push_back(-10);
  while (q--) {
    scanf("%d%d", &query, &x);
    if (query == 1) {
      msgs.push_back(x);
      firstUnread[x].push(msgs.size() - 1);
      unread[x]++;
      output++;
    } else if (query == 2) {
      output -= unread[x];
      unread[x] = 0;
      clear(firstUnread[x]);
    } else if (query == 3 and x > lastT) {
      for (int i = lastT; i <= x; i++) {
        if (firstUnread[msgs[i]].size() == 0) continue;
        if (i >= firstUnread[msgs[i]].front()) {
          firstUnread[msgs[i]].pop();
          unread[msgs[i]]--;
          output--;
        }
      }
      lastT = x + 1;
    }
    printf("%d\n", output);
  }
  return 0;
}

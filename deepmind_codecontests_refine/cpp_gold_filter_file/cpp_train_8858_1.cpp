#include <bits/stdc++.h>
using namespace std;
queue<int> q, ans;
pair<int, int> sp[1001];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &sp[i].first, &sp[i].second);
  }
  sort(sp, sp + n - 1);
  bool flag = true;
  int j = 1;
  for (int i = 0; i < n - 1; i++) {
    flag &= (sp[i].second == n);
    if (flag == false) break;
    while (sp[i].first > j) {
      q.push(j);
      j++;
    }
    if (sp[i].first == j) {
      ans.push(j);
      j++;
      continue;
    } else {
      if (q.empty())
        flag = false;
      else {
        int front = q.front();
        q.pop();
        ans.push(front);
      }
    }
  }
  if (flag) {
    printf("YES\n");
    int prev = ans.front();
    ans.pop();
    while (!ans.empty()) {
      int now = ans.front();
      ans.pop();
      printf("%d %d\n", prev, now);
      prev = now;
    }
    printf("%d %d\n", prev, n);
  } else {
    printf("NO\n");
  }
  return 0;
}

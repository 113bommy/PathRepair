#include <bits/stdc++.h>
using namespace std;
long long p[200010];
int main() {
  int n;
  scanf("%d", &n);
  ;
  priority_queue<long long, vector<long long>, greater<long long>> que;
  for (int i = (1); i < int(n + 1); i++) {
    scanf("%lld", &p[i]);
    que.push(p[i]);
  }
  long long sum = 0;
  if (que.size() % 2 == 0) que.push(0);
  while (que.size() > 1) {
    long long t = 0;
    t += que.top();
    que.pop();
    t += que.top();
    que.pop();
    t += que.top();
    que.pop();
    sum += t;
    que.push(t);
  }
  printf("%lld", sum);
}

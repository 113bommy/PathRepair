#include <bits/stdc++.h>
using namespace std;
priority_queue<long long> q;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < k; i++) q.push(0);
  for (int i = 0; i < n; i++) {
    long long s, m;
    scanf("%d%d", &s, &m);
    long long num = q.top();
    q.pop();
    num = max(-num, s);
    printf("%I64d\n", m + num);
    q.push(-(m + num));
  }
  return 0;
}

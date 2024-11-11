#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int main() {
  int N, p;
  long long ans;
  cin >> N;
  while (N--) {
    scanf("%d", &p);
    pq.push(-p);
    pq.push(-p);
    ans += p + pq.top();
    pq.pop();
  }
  cout << ans;
}

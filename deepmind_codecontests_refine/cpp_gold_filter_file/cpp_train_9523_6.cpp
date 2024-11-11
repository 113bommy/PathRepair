#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  queue<int> q;
  stack<int> s;
  cin >> n >> m;
  --m;
  for (int i = n - 2; i >= 0; --i) {
    if (m >= (1LL << i)) {
      m -= (1LL << i);
      s.push(n - i - 1);
    } else {
      q.push(n - i - 1);
    }
  }
  q.push(n);
  while (!q.empty()) {
    printf("%d ", q.front());
    q.pop();
  }
  while (!s.empty()) {
    printf("%d ", s.top());
    s.pop();
  }
}

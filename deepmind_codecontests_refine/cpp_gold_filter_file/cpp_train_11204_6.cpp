#include <bits/stdc++.h>
using namespace std;
const int N = 300004;
priority_queue<int> q;
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  int r = n;
  q.push(-1);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    q.push(x);
    while (!q.empty()) {
      if (q.top() == r) {
        r--;
        q.pop();
      } else
        break;
    }
    a[i] = q.size();
  }
  printf("1 ");
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}

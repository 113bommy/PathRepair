#include <bits/stdc++.h>
using namespace std;
int n;
bool a[100001];
bool uyg(int x) {
  if (x == n || a[x + 1] == 1) {
    a[x] = 1;
    return 1;
  }
  return 0;
}
int main() {
  int q;
  vector<int> v;
  priority_queue<int> pq;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &q);
    v.push_back(q);
  }
  for (int i = 0; i < n; i++) {
    if (uyg(v[i])) {
      printf("%d ", v[i]);
      if (!pq.empty())
        while (uyg(pq.top())) {
          printf("%d ", pq.top());
          pq.pop();
          if (pq.empty()) break;
        }
      if (i != n - 1) printf("\n");
    } else {
      printf("\n");
      pq.push(v[i]);
    }
  }
}

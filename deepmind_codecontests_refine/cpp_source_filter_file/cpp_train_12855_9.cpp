#include <bits/stdc++.h>
using namespace std;
struct T {
  int x;
  int l;
  int r;
} data[200001];
bool operator<(T a, T b) { return a.x > b.x; }
int a[200001];
int ans[200001];
int main(void) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    data[i].x = a[i];
  }
  stack<int> s;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (s.empty()) {
      data[i].l = -1;
    } else {
      data[i].l = s.top();
    }
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (s.empty()) {
      data[i].r = n + 1;
    } else {
      data[i].r = s.top();
    }
    s.push(i);
  }
  sort(data + 1, data + 1 + n);
  int donetill = 0;
  for (int i = 1; i <= n; i++) {
    int r = data[i].r - data[i].l - 1;
    if (r > donetill) {
      for (int j = donetill + 1; j <= r; j++) {
        ans[j] = data[i].x;
      }
      donetill = r;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}

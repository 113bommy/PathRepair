#include <bits/stdc++.h>
using namespace std;
struct st {
  int x, id;
  bool operator<(const st &b) const { return x < b.x; }
} a[200005];
char s[400005];
priority_queue<int> q;
int main() {
  int n, c1, c2;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].x);
    a[i].id = i + 1;
  }
  cin >> s;
  sort(a, a + n);
  c1 = c2 = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '0') {
      printf("%d ", a[c1].id);
      q.push(a[c1].id);
      c1++;
    } else {
      cout << q.top() << " ";
      q.pop();
    }
  }
  cout << endl;
  return 0;
}

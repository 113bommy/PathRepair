#include <bits/stdc++.h>
using namespace std;
int x, y, z, t, n;
const int MAXN = 1000005;
int b[10000000];
char c[200005];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    scanf("%s", c + 1);
    queue<int> a0;
    queue<int> a1;
    int id = 0;
    for (int i = 1; i <= n; i++) {
      x = c[i] - '0';
      if (x == 1) {
        if (!a1.empty()) {
          int top = a1.front();
          a1.pop();
          b[i] = top;
          a0.push(top);
        } else {
          b[i] = ++id;
          a0.push(id);
        }
      }
      if (x == 0) {
        if (!a0.empty()) {
          int top = a0.front();
          a0.pop();
          b[i] = top;
          a1.push(top);
        } else {
          b[i] = ++id;
          a1.push(id);
        }
      }
    }
    printf("%d\n", id);
    for (int i = 1; i <= n; i++) {
      printf("%d ", b[i]);
    }
    if (t) cout << endl;
  }
  return 0;
}

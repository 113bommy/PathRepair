#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;
class Segment {
 public:
  int left, right;
};
Segment s[MAXN];
int min(int a, int b) { return (a < b) ? a : b; }
int max(int a, int b) { return (a > b) ? a : b; }
int main() {
  int N;
  int x1, x2;
  while (1 == scanf("%d", &N)) {
    x1 = 1000000000;
    x2 = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d%d", &s[i].left, &s[i].right);
      x1 = min(x1, s[i].left);
      x2 = max(x2, s[i].right);
    }
    int result = 0;
    for (int i = 0; i < N; i++) {
      if (s[i].left == x1 && s[i].right == x2) {
        result = i;
        break;
      }
    }
    printf("%d\n", ++result);
  }
  return 0;
}

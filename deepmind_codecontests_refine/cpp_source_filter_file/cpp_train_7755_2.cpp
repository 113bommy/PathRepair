#include <bits/stdc++.h>
using namespace std;
struct NODE {
  int a, b;
  bool operator<(const NODE& other) const {
    return a < other.a || a == other.a && b < other.b;
  }
};
map<NODE, NODE> _map;
int N, half, a[500], b[500], c[500];
void dfs(int now, int A, int B, int C, int sum) {
  if (now > half) {
    NODE QAQ = (NODE){A - C, A - B};
    if (_map.count(QAQ)) {
      if (_map[QAQ].a < A) _map[QAQ] = (NODE){A, sum};
    } else
      _map[QAQ] = (NODE){A, sum};
    return;
  }
  dfs(now + 1, A + a[now], B + b[now], C, sum * 3);
  dfs(now + 1, A + a[now], B, C + c[now], sum * 3 + 1);
  dfs(now + 1, A, B + b[now], C + c[now], sum * 3 + 2);
}
int answer = -1000000, _from, _to;
void dfs2(int now, int A, int B, int C, int sum) {
  if (now <= half) {
    NODE QAQ = (NODE){C - A, B - A};
    if (_map.count(QAQ)) {
      if (_map[QAQ].a + A > answer) {
        answer = _map[QAQ].a + A;
        _from = _map[QAQ].b;
        _to = sum;
      }
    }
    return;
  }
  dfs2(now - 1, A + a[now], B + b[now], C, sum * 3);
  dfs2(now - 1, A + a[now], B, C + c[now], sum * 3 + 1);
  dfs2(now - 1, A, B + b[now], C + c[now], sum * 3 + 2);
}
void writechar(int now) {
  if (now == 0) printf("LM\n");
  if (now == 1) printf("LW\n");
  if (now == 2) printf("MW\n");
}
int _count = 0, num[1000];
void write() {
  int i;
  for (i = 1; i <= half; _from /= 3, i++) num[++_count] = _from % 3;
  for (i = _count; i > 0; i--) writechar(num[i]);
  for (i = 1; i <= N - half; _to /= 3, i++) writechar(_to % 3);
  exit(0);
}
int main() {
  scanf("%d", &N);
  half = N >> 1;
  int i;
  for (i = 1; i <= N; i++) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }
  dfs(1, 0, 0, 0, 0);
  dfs2(N, 0, 0, 0, 0);
  if (answer == -1000000) {
    printf("Impossible");
  } else
    write();
  return 0;
}

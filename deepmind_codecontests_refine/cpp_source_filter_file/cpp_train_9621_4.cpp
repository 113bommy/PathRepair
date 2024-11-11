#include <bits/stdc++.h>
using namespace std;
long long S;
class Line {
 public:
  long long a, b;
  long long dd;
};
long long cachetime(Line p, Line q) {
  long long a = q.a - p.a, b = p.b - q.b;
  return (b + a - 1) / a;
}
const int maxn = 200000 + 10;
Line q[maxn];
int head, tail;
struct VC {
  long long v, c;
};
bool operator<(VC a, VC b) { return a.c < b.c || (a.c == b.c && a.v > b.v); }
VC b[maxn];
int n;
void init() {
  cin >> n >> S;
  for (int i = 0; i < n; i++) {
    int v, c;
    scanf("%d%d", &v, &c);
    b[i].v = v;
    b[i].c = c;
  }
  sort(b, b + n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j && b[i].v <= b[j - 1].v) {
    } else {
      b[j++] = b[i];
    }
  }
  n = j;
}
long long work() {
  head = 0, tail = -1;
  Line l;
  l.a = b[0].v;
  l.b = 0;
  q[++tail] = l;
  int i = 1;
  while (i < n) {
    long long tl = (b[i].c - q[head].b + q[head].a - 1) / q[head].a;
    long long ts = (S - q[head].b + q[head].a - 1) / q[head].a;
    if (head < tail && q[head + 1].dd <= tl) {
      if (q[head + 1].dd >= ts) {
        return ts;
      }
      head++;
      continue;
    }
    if (tl >= ts) {
      return ts;
    }
    long long mon = tl * (q[head].a - b[i].v) + (q[head].b - b[i].c);
    l.a = b[i].v;
    l.b = mon;
    while (head + 1 <= tail) {
      l.dd = cachetime(q[tail], l);
      if (l.dd <= q[tail].dd) {
        tail--;
      } else {
        break;
      }
    }
    q[++tail] = l;
    i++;
  }
  while (true) {
    long long ts = (S - q[head].b + q[head].a - 1) / q[head].a;
    if (head == tail) return ts;
    if (q[head + 1].dd >= ts) return ts;
    head++;
  }
  return 0;
}
int main() {
  init();
  long long res = work();
  cout << res << endl;
  return 0;
}

#include <bits/stdc++.h>
const double PI = acos(-1.0);
const double EPS = 1E-9;
const long long INF = (long long)5E18;
using namespace std;
int N, M;
long long H, K;
int L;
long long ki[25];
long long dst[100005];
long long a[100005];
int val[100005];
bool v[100005], inq[100005];
void dijkstra() {
  for (int i = 0; i < (K); i++) dst[i] = INF;
  dst[0] = 0;
  priority_queue<long long, vector<long long>, greater<long long> > pq;
  pq.push(0);
  while (!pq.empty()) {
    long long x = pq.top();
    pq.pop();
    if (x > dst[x % K]) continue;
    for (int j = 0; j < (L); j++) {
      long long y = x + ki[j];
      if (y < dst[y % K]) {
        dst[y % K] = y;
        pq.push(y);
      }
    }
  }
}
struct trea {
  int id;
  int val;
  bool operator<(const trea &ano) const {
    if (val == ano.val) {
      return id > ano.id;
    }
    return val < ano.val;
  }
};
priority_queue<trea> tpq;
int main() {
  cin >> H >> N >> M >> K;
  memset(inq, 0, sizeof(inq));
  trea now;
  for (int i = 0; i < (N); i++) {
    scanf("%I64d%d", &a[i], &val[i]);
    if ((a[i] - 1) % K == 0) {
      now.id = i;
      now.val = val[i];
      tpq.push(now);
      inq[i] = 1;
    }
  }
  memset(v, 0, sizeof(v));
  ki[0] = K;
  L = 1;
  for (int i = 0; i < (M); i++) {
    int c;
    scanf("%d", &c);
    if (c == 1) {
      long long k;
      scanf("%I64d", &k);
      ki[L++] = k;
      dijkstra();
      for (int j = 0; j < (N); j++) {
        if (!inq[j] && dst[(a[j] - 1) % K] <= a[j]) {
          now.id = j;
          now.val = val[j];
          tpq.push(now);
          inq[j] = 1;
        }
      }
    } else if (c == 2) {
      int a, b;
      scanf("%d%d", &a, &b);
      val[a - 1] -= b;
      v[a - 1] = 1;
    } else if (c == 3) {
      if (tpq.empty()) {
        printf("0\n");
      } else {
        while (1) {
          now = tpq.top();
          tpq.pop();
          if (v[now.id]) {
            v[now.id] = 0;
            now.val = val[now.id];
            tpq.push(now);
            continue;
          }
          printf("%d\n", now.val);
          break;
        }
      }
    }
  }
  return 0;
}

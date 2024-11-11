#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
inline void read(long long &x) {
  char ch;
  bool flag = false;
  for (ch = getchar(); !isdigit(ch); ch = getchar())
    if (ch == '-') flag = true;
  for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar())
    ;
  x = flag ? -x : x;
}
int const maxn = 120000;
long long n, m, k;
struct zy {
  long long day, x, cost;
} A[maxn], B[maxn];
int totA, totB;
struct kkk {
  long long day, cost;
};
bool cmp(zy A, zy B) { return A.day < B.day; }
struct kkkkk {
  deque<kkk> a;
  int l = 0, r = -1;
  void push(kkk x) {
    while ((!a.empty()) && (x.cost <= a.back().cost)) a.pop_back();
    a.push_back(x);
  }
  long long pop(long long lim) {
    long long tmp = (*a.begin()).cost;
    while ((!a.empty()) && ((*a.begin()).day < lim)) a.pop_front();
    if (a.empty()) return -1;
    return (*a.begin()).cost - tmp;
  }
  long long top() { return (*a.begin()).cost; }
  bool Empty() { return a.empty(); }
} leave[maxn];
long long Min[maxn];
bool vis[maxn];
int main() {
  read(n);
  read(m);
  read(k);
  for (int i = 1; i <= m; i++) {
    long long a, b, c, d;
    read(a);
    read(b);
    read(c);
    read(d);
    zy tmp;
    tmp.day = a;
    tmp.x = b + c;
    tmp.cost = d;
    if (c == 0)
      A[++totA] = tmp;
    else
      B[++totB] = tmp;
  }
  sort(A + 1, A + 1 + totA, cmp);
  sort(B + 1, B + 1 + totB, cmp);
  int cnt = 0;
  int stA = 0;
  memset(Min, 63, sizeof(Min));
  for (int i = 1; i <= totA; i++) {
    Min[A[i].x] = min(Min[A[i].x], A[i].cost);
    if (!vis[A[i].x]) {
      vis[A[i].x];
      cnt++;
      if (cnt == n) {
        stA = i;
        break;
      }
    }
  }
  if (cnt != n) {
    puts("-1");
    return 0;
  }
  int stB = 0;
  for (int i = 1; i <= totB; i++)
    if (B[i].day >= A[stA].day + k + 1) {
      stB = i;
      break;
    }
  for (int i = stB; i <= totB; i++)
    if (B[i].day >= A[stA].day + k + 1) {
      kkk tmp;
      tmp.cost = B[i].cost;
      tmp.day = B[i].day;
      leave[B[i].x].push(tmp);
    }
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (leave[i].Empty()) {
      puts("-1");
      return 0;
    }
    sum = sum + Min[i] + leave[i].top();
  }
  long long ans = sum;
  for (int i = 1; i <= totA; i++) {
    int r = i - 1;
    while ((r < totA) && (A[r + 1].day == A[i].day)) {
      r++;
      if (Min[A[r].x] > A[r].cost) {
        sum += A[r].cost - Min[A[r].x];
        Min[A[r].x] = A[r].cost;
      }
    }
    i = r;
    while ((stB <= totB) && (B[stB].day < A[i].day + k + 1)) {
      long long tmp = leave[B[stB].x].pop(A[i].day + k + 1);
      if (leave[B[stB].x].Empty()) break;
      sum += tmp;
      stB++;
    }
    if (leave[B[stB].x].Empty()) break;
    ans = min(ans, sum);
  }
  printf("%d\n", ans);
  return 0;
}

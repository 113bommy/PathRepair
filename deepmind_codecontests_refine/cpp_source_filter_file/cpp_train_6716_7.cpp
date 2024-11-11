#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
int print_value(A title, B val) {
  cout << title << " = " << val << "\n";
  return 1;
}
int break_point() {
  char c;
  while ((c = getchar()) != '\n')
    ;
  return 0;
}
template <typename A>
int logg(A v) {
  cout << v << "\n";
  return 0;
}
template <typename T>
void read_integer(T &r) {
  bool sign = 0;
  r = 0;
  char c;
  while (1) {
    c = getchar();
    if (c == '-') {
      sign = 1;
      break;
    }
    if (c != ' ' && c != '\n') {
      r = c - '0';
      break;
    }
  }
  while (1) {
    c = getchar();
    if (c == ' ' || c == '\n') break;
    r = r * 10 + (c - '0');
  }
  if (sign) r = -r;
}
void run();
int main() {
  srand(time(NULL));
  do {
    run();
    if (0) {
      0 ? printf("-------------------------------\n") : 0;
      0 ? printf("-------------------------------\n") : 0;
    }
  } while (0);
  return 0;
}
struct product {
  int num;
  int cost;
  product(int _n, int _c) : num(_n), cost(_c) {}
  bool operator<(const product &other) const {
    if (cost == other.cost) return num < other.num;
    return cost < other.cost;
  }
};
vector<product> p[2];
int a[200005];
int b[200005];
int a_min[200005];
int b_min[200005];
long long cost_a[200005];
long long cost_b[200005];
void run() {
  int n, m, k, s;
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (i && a[i] >= a[a_min[i - 1]])
      a_min[i] = a_min[i - 1];
    else
      a_min[i] = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    if (i && b[i] >= b[b_min[i - 1]])
      b_min[i] = b_min[i - 1];
    else
      b_min[i] = i;
  }
  int v, d;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &v, &d);
    p[v - 1].push_back(product(v, d));
  }
  sort(p[0].begin(), p[0].end());
  sort(p[1].begin(), p[1].end());
  int l = 0, r = n - 1;
  int res = -2;
  int f_a, f_b;
  while (l <= r) {
    int mid = (l + r) >> 1;
    long long mincost = LLONG_MAX;
    int toa = min(k, (int)p[0].size());
    int from_a = 0;
    int from_b = 0;
    for (int i = 0; i < toa; i++) {
      cost_a[i] = 1ll * a[a_min[mid]] * p[0][i].cost;
      if (i) cost_a[i] += cost_a[i - 1];
    }
    if (toa >= k && mincost > cost_a[k - 1]) {
      from_a = k;
      mincost = cost_a[k - 1];
    }
    int tob = min(k, (int)p[1].size());
    for (int i = 0; i < tob; i++) {
      cost_b[i] = 1ll * b[b_min[mid]] * p[1][i].cost;
      if (i) cost_b[i] += cost_b[i - 1];
      int remain = k - i - 1;
      if (toa >= remain && cost_b[i] + cost_a[remain - 1] < mincost) {
        mincost = cost_b[i] + cost_a[remain - 1];
        from_a = remain;
        from_b = i + 1;
      }
    }
    if (mincost <= s) {
      res = mid;
      f_a = from_a;
      f_b = from_b;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%d", res + 1);
  putchar('\n');
  if (res != -2) {
    int day = a_min[res] + 1;
    for (int i = 0; i < f_a; i++) {
      printf("%d%c%d", p[0][i].num, ' ', day);
      putchar('\n');
    }
    day = b_min[res] + 1;
    for (int i = 0; i < f_b; i++) {
      printf("%d%c%d", p[1][i].num, ' ', day);
      putchar('\n');
    }
  }
}

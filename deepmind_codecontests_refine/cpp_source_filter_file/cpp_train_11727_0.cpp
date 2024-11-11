#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long inf = 0xc0c0c0c0c0c0c0c0;
const double pi = acos(-1);
const int MAX = 1e5 + 7;
pair<int, int> tree[2][MAX << 2];
char in[MAX];
int lenA, lenB;
void w(pair<int, int> x) { printf("[B|C:%d A:%d]\n", x.first, x.second); }
pair<int, int> merge(pair<int, int> pl, pair<int, int> pr) {
  pair<int, int> ans = make_pair(pl.first + pr.first, pr.second);
  if (pr.first == 0) ans.second += pl.second;
  return ans;
}
void init(int l, int r, int pos, pair<int, int>* arr) {
  if (l == r) {
    if (in[l] == 'A')
      arr[pos] = make_pair(0, 1);
    else
      arr[pos] = make_pair(1, 0);
    return;
  }
  int mid = (l + r) >> 1;
  init(l, mid, pos << 1, arr);
  init(mid + 1, r, pos << 1 | 1, arr);
  arr[pos] = merge(arr[pos << 1], arr[pos << 1 | 1]);
}
pair<int, int> query(int from, int to, int l, int r, int pos,
                     pair<int, int>* arr) {
  if (from <= l && to >= r) return arr[pos];
  pair<int, int> ans = make_pair(0, 0);
  int mid = (l + r) >> 1;
  if (from <= mid) ans = merge(ans, query(from, to, l, mid, pos << 1, arr));
  if (mid < to)
    ans = merge(ans, query(from, to, mid + 1, r, pos << 1 | 1, arr));
  return ans;
}
int main() {
  scanf("%s", in);
  lenA = strlen(in);
  init(0, lenA, 1, tree[0]);
  scanf("%s", in);
  lenB = strlen(in);
  init(0, lenB, 1, tree[1]);
  int Q;
  scanf("%d", &Q);
  while (Q--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    a--;
    b--;
    c--;
    d--;
    pair<int, int> x = query(a, b, 0, lenA, 1, tree[0]);
    pair<int, int> y = query(c, d, 0, lenB, 1, tree[1]);
    if (x.first > y.first)
      putchar('0');
    else if ((x.first ^ y.first) & 1)
      putchar('0');
    else if (x.second < y.second)
      putchar('0');
    else if (y.second < x.second && x.first < y.first)
      putchar('1');
    else if (x.second == y.second && x.first < y.first)
      putchar('0');
    else if ((x.second - y.second) % 3)
      putchar('0');
    else
      putchar('1');
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b);
long long gcd(long long a, long long b);
long long cross_prod(long long ax, long long ay, long long bx, long long by,
                     long long cx, long long cy);
long long sum_digit(long long A);
long long get_mask(long long x);
long long get_nr(string &S, int pos, int lg);
bool cmp_pair_ii1(pair<int, int> A, pair<int, int> B);
bool cmp_i2(int A, int B);
string next_word(string &S, int &pos);
long long rise(long long x, long long p);
double dist(int a, int b, int x, int y);
long long inv(long long x);
class SegmentTree {
 public:
  vector<int> V;
  void init(int dim);
  int query(int start, int end, int pos, int node);
  void build(int start, int end, int node);
};
long long N;
int main() {
  long long x;
  scanf("%d", &N);
  N = abs(N);
  x = 0;
  while (x * (x + 1) < 2 * N) ++x;
  while (((x * (x + 1) / 2) & 1) != (N & 1)) ++x;
  cout << x;
  return 0;
}
long long inv(long long x) { return rise(x, 1000000000 - 2); }
double dist(int a, int b, int x, int y) {
  double t1, t2;
  t1 = a - x;
  t1 *= t1;
  t2 = b - y;
  t2 *= t2;
  return sqrt(t1 + t2);
}
bool cmp_pair_ii1(pair<int, int> A, pair<int, int> B) {
  return A.first < B.first;
}
bool cmp_i2(int A, int B) { return A > B; }
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long cross_prod(long long ax, long long ay, long long bx, long long by,
                     long long cx, long long cy) {
  return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}
long long sum_digit(long long A) {
  long long sum = 0;
  do {
    sum += A % 10;
    A /= 10;
  } while (A);
  return sum;
}
long long get_mask(long long x) {
  long long mask = 0, c;
  while (x) {
    c = x % 10;
    x /= 10;
    if (c == 4 || c == 7) {
      mask = mask * 10 + c;
    }
  }
  return mask;
}
void SegmentTree::init(int dim) { V.resize((dim + 1) << 2); }
void SegmentTree::build(int start, int end, int node) {
  V[node] = end - start + 1;
  if (start == end) {
    return;
  }
  int mid;
  mid = (start + end) >> 1;
  build(start, mid, (node << 1));
  build(mid + 1, end, ((node << 1) | 1));
}
int SegmentTree::query(int start, int end, int pos, int node) {
  --V[node];
  if (start == end) return end;
  int L, R;
  L = node << 1;
  R = L | 1;
  int mid;
  mid = (start + end) >> 1;
  if (pos <= V[L]) {
    return query(start, mid, pos, L);
  } else {
    return query(mid + 1, end, pos - V[L], R);
  }
}
long long get_nr(string &S, int pos, int lg) {
  long long nr = 0;
  while (lg) {
    nr = nr * 10 + (S[pos] - '0');
    ++pos;
    --lg;
  }
  return nr;
}
string next_word(string &S, int &pos) {
  int pos_l, pos_sp;
  if (S[S.length() - 1] != ' ') {
    S += ' ';
  }
  pos_l = S.find_first_not_of(" ", pos);
  if (pos_l == -1) {
    pos = -1;
    return "";
  }
  pos_sp = S.find_first_of(" ", pos_l);
  pos = pos_sp;
  return S.substr(pos_l, pos_sp - pos_l);
}
long long rise(long long x, long long p) {
  if (p == 1) {
    return x;
  }
  long long res = rise(x, p / 2);
  res %= 1000000000;
  if (p & 1) {
    return (((res * res) % 1000000000) * x) % 1000000000;
  } else {
    return ((res * res) % 1000000000);
  }
}

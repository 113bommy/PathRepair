#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 7;
const double EPS = 1e-9;
int bit_count(int first) {
  return first == 0 ? 0 : 1 + bit_count(first & (first - 1));
}
inline int low_bit(int first) { return first & -first; }
inline int sign(double first) {
  return first < -EPS ? -1 : first > EPS ? 1 : 0;
}
inline int sign(int first) { return (first > 0) - (first < 0); }
int nextComb(int first) {
  if (!first) {
    fprintf(stderr, "nextComb(0) called\n");
    return ((1 << 30) - 1 + (1 << 30));
  }
  int smallest = first & -first;
  int ripple = first + smallest;
  int ones = first ^ ripple;
  ones = (ones >> 2) / smallest;
  return ripple | ones;
}
template <class T>
inline T gcd(T a, T b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
inline int getInt() {
  int a;
  return scanf("%d", &a) ? a : (fprintf(stderr, "trying to read\n"), -1);
}
inline double getDouble() {
  double a;
  return scanf("%lf", &a) ? a : (fprintf(stderr, "trying to read\n"), -1.0);
}
inline double myRand() {
  return ((double)rand() / RAND_MAX) + ((double)rand() / RAND_MAX / RAND_MAX);
}
const int N = 109;
int s, c;
int Left[N], Right[N];
vector<pair<int, pair<int, int> > > getOptions(int n) {
  vector<pair<int, pair<int, int> > > ret;
  for (int i = (int)0; i < (int)s; ++i) {
    if (Left[i] == -1) {
      int L = c - n / 2, R = c + (n - 1) / 2, cost = 0;
      for (int j = L; j <= R; ++j) cost += abs(c - i) + abs(c - j);
      ret.push_back(make_pair(cost, pair<int, int>(i, L)));
    } else {
      int L = Left[i] - n, R = Left[i] - 1, cost = 0;
      if (L >= 0) {
        for (int j = L; j <= R; ++j) cost += abs(c - i) + abs(c - j);
        ret.push_back(make_pair(cost, pair<int, int>(i, L)));
      }
      L = Right[i] + 1;
      R = Right[i] + n;
      cost = 0;
      if (R < s) {
        for (int j = L; j <= R; ++j) cost += abs(c - i) + abs(c - j);
        ret.push_back(make_pair(cost, pair<int, int>(i, L)));
      }
    }
  }
  return ret;
}
void update(int first, int a, int b) {
  if (Left[first] == -1) {
    Left[first] = a;
    Right[first] = b;
  } else {
    if (a < Left[first]) Left[first] = a;
    if (b > Right[first]) Right[first] = b;
  }
}
void myCode() {
  int n = getInt();
  s = getInt();
  c = s / 2;
  for (int i = (int)0; i < (int)s; ++i) Left[i] = Right[i] = -1;
  for (int i = (int)0; i < (int)n; ++i) {
    int first = getInt();
    if (first > s) {
      printf("-1\n");
      continue;
    }
    vector<pair<int, pair<int, int> > > a = getOptions(first);
    if (a.empty()) {
      printf("-1\n");
      continue;
    }
    sort((a).begin(), (a).end());
    printf("%d %d %d\n", a[0].second.first + 1, a[0].second.second + 1,
           a[0].second.second + first);
    update(a[0].second.first, a[0].second.second,
           a[0].second.second + first - 1);
  }
}
int main() {
  srand(time(NULL));
  myCode();
  return 0;
}

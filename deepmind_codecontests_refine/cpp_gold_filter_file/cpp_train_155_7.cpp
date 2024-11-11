#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = 1000001000;
const int mod = 1000 * 1000 * 1000 + 7;
const int mod9 = 1000 * 1000 * 1000 + 9;
const double PI = 3.1415926535897932;
double sqr(double first) { return first * first; };
long double sqr(long double first) { return first * first; };
long long sqr(long long first) { return first * first; };
long long sqr(int first) { return first * 1LL * first; };
long long gcd(long long a, long long b) {
  while (b) a %= b, swap(a, b);
  return a;
}
long long bpm(long long a, long long n = -2, long long m = mod) {
  n = n >= 0 ? n : m + n;
  long long r = 1;
  while (n) {
    if (n & 1) r = (r * a) % m;
    a = (a * a) % m;
    n >>= 1;
  }
  return r;
}
long long dist(long long x1, long long y1, long long x2, long long y2) {
  return sqr(x1 - x2) + sqr(y1 - y2);
}
std::ostream& operator<<(std::ostream& os, pair<int, int> p) {
  return os << "{" << p.first << " " << p.second << "}";
}
const int N = 5003;
int z[N];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  ;
  int a, b;
  scanf("%d %d", &a, &b);
  ;
  int c, d;
  scanf("%d %d", &c, &d);
  ;
  set<int> st;
  for (int i = 0; i < n; i++) {
    st.insert(i + 1);
  }
  z[0] = a;
  z[1] = b;
  z[2] = c;
  z[3] = d;
  st.erase(a);
  st.erase(b);
  st.erase(c);
  st.erase(d);
  if (st.size() == 0) {
    cout << -1 << endl;
    return 0;
  }
  int e = *st.begin();
  st.erase(e);
  set<pair<int, int> > rds;
  vector<int> r1, r2;
  vector<int> in;
  while (st.size()) {
    in.push_back(*st.begin());
    st.erase(st.begin());
  }
  r1.push_back(a);
  for (int first : in) {
    r1.push_back(first);
  }
  r1.push_back(d);
  r1.push_back(e);
  r1.push_back(c);
  r1.push_back(b);
  r2.push_back(c);
  r2.push_back(b);
  r2.push_back(e);
  r2.push_back(a);
  for (int first : in) {
    r2.push_back(first);
  }
  r2.push_back(d);
  for (int i = 1; i < r1.size(); i++) {
    pair<int, int> f = {r1[i], r1[i - 1]};
    if (f.first > f.second) {
      swap(f.first, f.second);
    }
    rds.insert(f);
  }
  for (int i = 1; i < r2.size(); i++) {
    pair<int, int> f = {r2[i], r2[i - 1]};
    if (f.first > f.second) {
      swap(f.first, f.second);
    }
    rds.insert(f);
  }
  if (rds.size() > k) {
    cout << -1 << endl;
    return 0;
  }
  {
    for (int i = 0; i < r1.size(); i++)
      if (i + 1 == r1.size())
        printf("%d\n", r1[i]);
      else
        printf("%d ", r1[i]);
  };
  {
    for (int i = 0; i < r2.size(); i++)
      if (i + 1 == r2.size())
        printf("%d\n", r2[i]);
      else
        printf("%d ", r2[i]);
  };
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  } else {
    return b;
  }
}
vector<string> split(const string& s, char c) {
  vector<string> v;
  stringstream ss(s);
  string x;
  while (getline(ss, x, c)) v.emplace_back(x);
  return move(v);
}
void err(vector<string>::iterator it) {}
template <typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
  cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << ", ";
  err(++it, args...);
}
template <typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T> {
  T v;
  number_iterator(T _v) : v(_v) {}
  operator T&() { return v; }
  T operator*() const { return v; }
};
template <typename T>
struct number_range {
  T b, e;
  number_range(T b, T e) : b(b), e(e) {}
  number_iterator<T> begin() { return b; }
  number_iterator<T> end() { return e; }
};
template <typename T>
number_range<T> range(T e) {
  return number_range<T>(1, e + 1);
}
template <typename T>
number_range<T> range(T b, T e) {
  return number_range<T>(b, e + 1);
}
int n, p[601];
double sta, pp, res;
double ex[601];
int now;
double cc(int id) {
  return pp / ex[id] *
         (1.00 - (1.00 - ex[id]) * (1.00 - (double)p[id] / 100.00));
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &p[i]);
  if (n == 1) {
    puts("1.0000");
    return 0;
  }
  pp = 1.00;
  for (int i = (1); i <= (n); i++) pp = pp * (double)p[i] / 100.00;
  for (int i = (1); i <= (n); i++) ex[i] = (double)p[i] / 100.00;
  now = n;
  res += (double)now * pp;
  sta = pp;
  for (int j = (now + 1); j <= (100000); j++) {
    int ma = 1;
    double fu = cc(ma);
    for (int k = (2); k <= (n); k++) {
      double fx = cc(k);
      if (fx > fu) {
        ma = k;
        fu = fx;
      }
    }
    pp /= ex[ma];
    ex[ma] = 1.00 - (1.00 - ex[ma]) * (1.00 - (double)p[ma] / 100.00);
    pp *= ex[ma];
    res += (double)j * (pp - sta);
    sta = pp;
  }
  printf("%.12lf\n", res);
  return 0;
}

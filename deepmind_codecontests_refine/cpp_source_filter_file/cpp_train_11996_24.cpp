#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using vb = vector<bool>;
using vc = vector<char>;
using vd = vector<double>;
using vi = vector<int>;
using vvi = vector<vi>;
using vlli = vector<lli>;
using vvlli = vector<vlli>;
using pi = pair<int, int>;
using plli = pair<lli, lli>;
void readc(char &q) { scanf("%c", &q); }
char readc() {
  char q;
  scanf("%c", &q);
  return q;
}
void readint(int &q) { scanf("%d", &q); }
int readint() {
  int q;
  scanf("%d", &q);
  return q;
}
void readlong(lli &q) { scanf("%lld", &q); }
lli readlong() {
  lli q;
  scanf("%lld", &q);
  return q;
}
void readdbl(double &q) { scanf("%lf", &q); }
double readdbl() {
  double q;
  scanf("%lf", &q);
  return q;
}
void printint(int q) { printf("%d", q); }
void printlong(lli q) { printf("%lld", q); }
inline void printdbl(double q, int p = 6) { printf("%.*lf", p, q); }
void readln() { scanf("\n"); }
void println() { printf("\n"); }
void printsp() { printf(" "); }
void print(int q) { printint(q); }
void print(long q) { printlong((lli)q); }
void print(lli q) { printlong(q); }
void print(double q) { printdbl(q); }
inline void print(char c) { printf("%c", c); }
void print(pi q) {
  print(q.first);
  printsp();
  print(q.second);
}
void print(vi q) {
  for (int i = 0; i < q.size(); ++i) {
    print(q[i]);
    printsp();
  }
}
void print(vlli q) {
  for (int i = 0; i < q.size(); ++i) {
    print(q[i]);
    printsp();
  }
}
void print(vd q) {
  for (int i = 0; i < q.size(); ++i) {
    print(q[i]);
    printsp();
  }
}
template <typename T>
void println(T q) {
  print(q);
  println();
}
template <typename T>
T maxim(T first, T second) {
  return (first > second) ? first : second;
}
template <typename T>
T maxim(T first, T second, T third) {
  return mndlim(maxim(first, second), third);
}
template <typename T>
T minim(T first, T second) {
  return (first < second) ? first : second;
}
template <typename T>
T minim(T first, T second, T third) {
  return minim(minim(first, second), third);
}
template <typename T>
T middle(T first, T second, T third) {
  return first + second + third - maxim(first, second, third) -
         minim(first, second, third);
}
template <typename T>
T abs(T arg) {
  return arg < 0 ? -arg : arg;
}
const int modulo = 1000000007;
int a[5005];
vlli ans;
lli create_stint(lli base, int size) {
  for (int i = 0; i < size; ++i) {
    ans.push_back(base * (i + 1));
  }
  return *ans.rbegin() * 2;
}
int main() {
  int n = readint();
  int m = readint();
  a[3] = 1;
  for (int i = 4; i <= n; ++i) {
    a[i] = a[i - 1] + (i - 1) / 2;
  }
  int cnt = n;
  lli base = 1ll;
  if (m > a[n]) {
    println(-1);
    return 0;
  }
  int cur = 2;
  while (a[cur] <= m) {
    cur++;
  }
  cur--;
  for (int i = 0; i < cur; ++i) ans.push_back(i + 1);
  cnt -= cur;
  m -= a[cur];
  int last = *ans.rbegin();
  if (m > 0) {
    if (cnt > 0) {
      ans.push_back(2 * last - 2 * m + 1);
      cnt--;
      m = 0;
    } else {
      println(-1);
      return 0;
    }
  }
  last = *ans.rbegin();
  for (int i = 0; i < cnt; ++i) ans.push_back(100000 * (i + 1) + i);
  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
  println();
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
const long double pi = acos((long double)-1);
void in(initializer_list<int *> li) {
  for (auto ptr = li.begin(); ptr != li.end(); ptr++) scanf("%d", *ptr);
}
void in(initializer_list<long long *> li) {
  for (auto ptr = li.begin(); ptr != li.end(); ptr++) scanf("%lld", *ptr);
}
void in(initializer_list<double *> li) {
  for (auto ptr = li.begin(); ptr != li.end(); ptr++) scanf("%lf", *ptr);
}
void out(initializer_list<int> li) {
  for (auto ptr = li.begin(); ptr != li.end(); ptr++) printf("%d ", *ptr);
}
void outln(initializer_list<int> li) {
  for (auto ptr = li.begin(); ptr != li.end(); ptr++) printf("%d\n", *ptr);
}
void out(initializer_list<long long> li) {
  for (auto ptr = li.begin(); ptr != li.end(); ptr++) printf("%lld ", *ptr);
}
void outln(initializer_list<long long> li) {
  for (auto ptr = li.begin(); ptr != li.end(); ptr++) printf("%lld\n", *ptr);
}
int in(int &a, int &b, int &c, int &d) {
  return scanf("%d%d%d%d", &a, &b, &c, &d);
}
int in(int &a, int &b, int &c) { return scanf("%d%d%d", &a, &b, &c); }
int in(int &a, int &b) { return scanf("%d%d", &a, &b); }
int in(long long &a, long long &b) { return scanf("%lld%lld", &a, &b); }
int in(long long &a, long long &b, long long &c, long long &d) {
  return scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
}
int in(long long &a, long long &b, long long &c) {
  return scanf("%lld%lld%lld", &a, &b, &c);
}
int in(long long &a) { return scanf("%lld", &a); }
int in(int &a) { return scanf("%d", &a); }
int in(char *s) { return scanf("%s", s); }
int in(char &c) { return scanf("%c", &c); }
void out(int a, bool ln) { printf("%d%c", a, " \n"[ln]); }
void out(long long a, bool ln) { printf("%lld%c", a, " \n"[ln]); }
void out(double a, int digit, bool ln) {
  printf("%.*f%c", digit, a, " \n"[ln]);
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 1e6 + 5;
const int maxm = 1e6 + 5;
const long long mod = 1e9 + 7;
char a[300][300];
int main() {
  string s;
  cin >> s;
  int n = s.size();
  out(3, 1);
  printf("L 2\n");
  printf("R 2\n");
  printf("R %d", 2 * n - 1);
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
inline void read_string_to_vector(vector<string> &vec) {
  string str;
  getline(cin, str);
  vec.push_back(str);
}
template <typename T>
inline void read_digit_to_vector(vector<T> &vec) {
  T t;
  cin >> t;
  vec.push_back(t);
}
long long n;
char ch[] = {'0', '1'};
char s[1004];
long long answ[2];
void buildString(long long j, long long i) {
  for (register long long k = 0; k < i; ++k) s[k] = ch[j];
  j ^= 1;
  for (register long long k = i; k < n; ++k) s[k] = ch[j];
}
long long queryString(void) {
  printf("? %s\n", s);
  fflush(stdout);
  long long x;
  scanf("%lld", &x);
  return x;
}
long long buildAndQuery(long long j, long long i) {
  buildString(j, i);
  return queryString();
}
bool ft(long long j, long long i, long long c) {
  return buildAndQuery(j, i + 1) == (n - c - (i + 1ll));
}
long long bs(long long j, long long c) {
  long long l = 0, r = n - 1;
  while ((r - l) > 1) {
    long long md = (r + l) >> 1;
    if (!ft(j, md, c))
      r = md;
    else
      l = md;
  }
  return l + 1;
}
int main() {
  scanf("%lld", &n);
  long long a = buildAndQuery(0, n), b = buildAndQuery(1, 1);
  if (a > b)
    answ[1] = 0, answ[0] = bs(1, n - a);
  else
    answ[0] = 0, answ[1] = bs(0, a);
  printf("! %lld %lld\n", answ[0] + 1, answ[1] + 1);
  fflush(stdout);
  return 0;
}

#include <bits/stdc++.h>
template <class T>
T abst(const T &n) {
  return (n < 0 ? -n : n);
}
template <class T>
T max3(const T &a, const T &b, const T &c) {
  return max2(a, max2(b, c));
}
template <class T>
T min3(const T &a, const T &b, const T &c) {
  return min2(a, min2(b, c));
}
template <class T>
T gcd(const T a, const T b) {
  return (b ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(const T a, const T b) {
  return (a / gcd<T>(a, b) * b);
}
template <class T>
T sq(const T &x) {
  return x * x;
}
using namespace std;
int main() {
  int n, count = 0, i, len;
  char word[2002];
  scanf("%d", &n);
  getchar();
  gets(word);
  len = strlen(word);
  for (i = n; i <= len; i += n) {
    if (word[i - 1] == word[i - 2] && word[i - 2] == word[i - 3]) count += 1;
  }
  printf("%d", count);
}

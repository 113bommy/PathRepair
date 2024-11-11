#include <bits/stdc++.h>
using namespace std;
template <class T>
T min(const T& a, const T& b, const T& c) {
  return min(min(a, b), min(a, c));
}
template <class T>
T max(const T& a, const T& b, const T& c) {
  return max(max(a, b), max(a, c));
}
void debug() {}
int getch() {
  int ch;
  while ((ch = getchar()) != EOF) {
    if (ch != ' ' && ch != '\n') return ch;
  }
  return EOF;
}
const int maxn = 100005;
char s[maxn];
int ch[26] = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1,
              0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0};
int c() {
  for (int i = 0, j = strlen(s) - 1; i <= j; i++, j--) {
    if (s[i] != s[j] || ch[s[i] - 'A'] == 0) return 0;
  }
  return 1;
}
int main() {
  scanf("%s", s);
  printf("%s\n", c() ? "YES" : "NO");
  return 0;
}

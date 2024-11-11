#include <bits/stdc++.h>
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T>
inline void scand(T &x) {
  char c;
  x = 0;
  while ((c = getchar()) < '0')
    ;
  while (c >= '0' && c <= '9') x = x * 10 + (c - 48), c = getchar();
}
template <class T>
inline void gmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void gmin(T &a, T b) {
  if (b < a) a = b;
}
using namespace std;
const int N = 5050, M = 0, L = 0, Z = 1e9 + 7, t30 = 1 << 30,
          maxint = 2147483647, ms31 = 522133279, ms63 = 1061109567,
          ms127 = 2139062143;
const double eps = 1e-8, PI = acos(-1.0);
struct A {};
map<int, int> mop;
int casenum, casei, inf;
int n, i, j, k;
string s;
long long a[N];
char b[N];
long long count(string s) {
  int l = s.length(), i;
  int top1 = 0, top2 = 0;
  s[l - 1] = '+';
  for (i = 1; i < l; i++) {
    if (isdigit(s[i])) {
      long long tmp = 0;
      while (isdigit(s[i])) {
        tmp = tmp * 10 + s[i] - 48;
        i++;
      }
      a[++top1] = tmp;
      i--;
    } else if (s[i] == '+') {
      while (top2) {
        long long x, y, z;
        x = a[top1--];
        y = a[top1--];
        if (b[top2] == '+')
          z = x + y;
        else
          z = x * y;
        a[++top1] = z;
        top2--;
      }
      b[++top2] = s[i];
    } else if (s[i] == '*') {
      while (top2 && b[top2] == '*') {
        long long x, y, z;
        x = a[top1--];
        y = a[top1--];
        z = x * y;
        a[++top1] = z;
        top2--;
      }
      b[++top2] = s[i];
    }
  }
  return a[top1];
}
int main() {
  while (cin >> s) {
    s = '*' + s + '*';
    int l = s.length();
    long long ans = 0;
    for (i = 0; i < l; i++)
      if (s[i] == '*') {
        for (j = i + 1; j < l; j++)
          if (s[j] == '*') {
            string mid = s.substr(i, j - i + 1);
            long long tmp = count(mid);
            if (tmp == 0)
              mid = "0";
            else {
              mid = "";
              while (tmp) {
                char ch = tmp % 10 + 48;
                mid = ch + mid;
                tmp /= 10;
              }
              string a = s.substr(0, i + 1) + mid + s.substr(j, l);
              gmax(ans, count(a));
            }
          }
      }
    printf("%I64d\n", ans);
  }
  return 0;
}

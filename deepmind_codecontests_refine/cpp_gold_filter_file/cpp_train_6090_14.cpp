#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &first) {
  first = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    first = first * 10 + c - '0';
    c = getchar();
  }
  first *= f;
}
template <class T>
inline void umin(T &first, T second) {
  first = first < second ? first : second;
}
template <class T>
inline void umax(T &first, T second) {
  first = first > second ? first : second;
}
inline unsigned int R() {
  static unsigned int seed = 416;
  return seed ^= seed >> 5, seed ^= seed << 17, seed ^= seed >> 13;
}
const int N = 866666, mx = 1e5;
int n;
pair<int, int> s[N], sta[N];
int len, top;
void ins(int first, int second) {
  s[++len] = pair<int, int>(min(max(first, 0), mx), min(max(second, 0), mx));
}
inline double getlen(pair<int, int> a) {
  return sqrt(1LL * a.first * a.first + 1LL * a.second * a.second);
}
inline long long Cross(pair<int, int> a, pair<int, int> b) {
  return 1LL * a.first * b.second - 1LL * a.second * b.first;
}
pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return pair<int, int>(a.first - b.first, a.second - b.second);
}
double Abs(double first) { return first > 0 ? first : -first; }
bool cmp(pair<int, int> a, pair<int, int> b) {
  a = a - s[1];
  b = b - s[1];
  long long t = 1LL * a.first * b.second - 1LL * a.second * b.first;
  return t ? t > 0 : getlen(a) < getlen(b);
}
int main() {
  int v;
  read(n);
  for (register int i = (1); i <= (n); i++) {
    int first, second;
    read(first), read(second), read(v);
    if (first - v >= 0)
      ins(first - v, second);
    else
      ins(0, second + (v - first)), ins(0, second - (v - first));
    if (second - v >= 0)
      ins(first, second - v);
    else
      ins(first + (v - second), 0), ins(first - (v - second), 0);
    if (first + v <= mx)
      ins(first + v, second);
    else
      ins(mx, second + (v - mx + first)), ins(mx, second - (v - mx + first));
    if (second + v <= mx)
      ins(first, second + v);
    else
      ins(first + (v - mx + second), mx), ins(first - (v - mx + second), mx);
  }
  int p = 1;
  for (register int i = (2); i <= (len); i++)
    if (s[i].first < s[p].first ||
        s[i].first == s[p].first && s[i].second < s[p].second)
      p = i;
  swap(s[1], s[p]);
  sort(s + 2, s + len + 1, cmp);
  for (register int i = (1); i <= (len); i++) {
    while (top >= 2 && Cross(s[i] - sta[top - 1], sta[top] - sta[top - 1]) >= 0)
      top--;
    sta[++top] = s[i];
  }
  sta[top + 1] = sta[1];
  sta[top + 2] = sta[2];
  double ans = -1e100;
  int pp = 0;
  for (register int i = (1); i <= (top); i++) {
    double R = getlen(sta[i + 1] - sta[i]) * getlen(sta[i + 2] - sta[i]) *
               getlen(sta[i + 2] - sta[i + 1]) / 2 /
               Abs(Cross(sta[i + 2] - sta[i], sta[i + 1] - sta[i]));
    if (R > ans) ans = R, pp = i;
  }
  for (register int i = (pp); i <= (pp + 2); i++)
    printf("%d %d\n", sta[i].first, sta[i].second);
  return 0;
}

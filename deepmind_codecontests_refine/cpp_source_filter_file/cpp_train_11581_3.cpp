#include <bits/stdc++.h>
using namespace std;
const int LETTER = 26;
static int C = 13331;
template <int M, class B>
struct A {
  int x;
  B b;
  A(int x = 0) : x(x), b(x) {}
  A(int x, B b) : x(x), b(b) {}
  A operator+(A o) {
    int y = x + o.x;
    return {y - (y >= M) * M, b + o.b};
  }
  A operator-(A o) {
    int y = x - o.x;
    return {y + (y < 0) * M, b - o.b};
  }
  A operator*(A o) { return {(int)(1LL * x * o.x % M), b * o.b}; }
  explicit operator uint64_t() { return x ^ (uint64_t)b << 21; }
  bool operator==(const A<M, B>& rhs) const { return x == rhs.x && b == rhs.b; }
};
struct HashInterval {
  vector<A<1000000007, A<1000000009, unsigned>>> ha, pw;
  HashInterval(string& str) : ha(str.length() + 1), pw(ha) {
    pw[0] = 1;
    for (int i = 0; i < str.length(); ++i)
      ha[i + 1] = ha[i] * C + str[i], pw[i + 1] = pw[i] * C;
  }
  A<1000000007, A<1000000009, unsigned>> hashInterval(int a, int b) {
    return ha[b] - ha[a] * pw[b - a];
  }
};
const int MAXN = 5010100;
struct Data {
  int l, r;
  bool operator<(const Data& rhs) const { return r - l > rhs.r - rhs.l; }
};
Data gao(const char* s) {
  int n = strlen(s), mxok = 0;
  Data ans;
  ans.l = 0, ans.r = n;
  while (mxok < n && s[mxok] == s[n - 1 - mxok]) mxok++;
  string s1, s2;
  for (int i = mxok; i < n - mxok; ++i) s1 += s[i], s2 += s[i];
  reverse(s2.begin(), s2.end());
  HashInterval h1(s1), h2(s2);
  for (int i = 0; i < s1.length(); ++i) {
    if (h1.hashInterval(0, i + 1) ==
        h2.hashInterval(s1.length() - 1 - i, s1.length()))
      ans = max(ans, (Data){i + mxok + 1, n - mxok - 1});
  }
  return ans;
}
char s[MAXN], t[MAXN];
void solve() {
  scanf("%s", s);
  int n = strlen(s), mxok = 0;
  while (mxok < n && s[mxok] == s[n - 1 - mxok]) mxok++;
  if (mxok >= n) {
    puts(s);
    return;
  }
  for (int i = 0; i < n; ++i) t[i] = s[n - 1 - i];
  t[n] = 0;
  auto ans = gao(s);
  auto ans1 = gao(t);
  char* tt = s;
  if (ans < ans1) {
    swap(ans1, ans);
    tt = t;
  }
  if (ans.l > 0) s[ans.l] = 0, printf("%s", tt);
  if (ans.r < n - 1) printf("%s", tt + ans.r + 1);
  printf("\n");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
  return 0;
}

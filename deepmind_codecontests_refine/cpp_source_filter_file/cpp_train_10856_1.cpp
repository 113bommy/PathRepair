#include <bits/stdc++.h>
using namespace std;
struct READ {
  inline char read() {
    const int LEN = 1 << 18 | 1;
    static char buf[LEN], *s, *t;
    return (s == t) && (t = (s = buf) + fread(buf, 1, LEN, stdin)),
           s == t ? -1 : *s++;
  }
  inline READ &operator>>(char *s) {
    char ch;
    while (isspace(ch = read()) && ~ch)
      ;
    while (!isspace(ch) && ~ch) *s++ = ch, ch = read();
    *s = '\0';
    return *this;
  }
  inline READ &operator>>(string &s) {
    s = "";
    char ch;
    while (isspace(ch = read()) && ~ch)
      ;
    while (!isspace(ch) && ~ch) s += ch, ch = read();
    return *this;
  }
  template <typename _Tp>
  inline READ &operator>>(_Tp &x) {
    char ch, flag;
    for (ch = read(), flag = 0; !isdigit(ch) && ~ch; ch = read())
      flag |= ch == '-';
    for (x = 0; isdigit(ch); ch = read()) x = x * 10 + (ch ^ '0');
    flag && (x = -x);
    return *this;
  }
} in;
const int N = 1e5 + 50;
vector<pair<int, int> > rec;
int main() {
  int n;
  in >> n;
  for (int i = 1; i <= 2 * n; i++) {
    char ch[2], x;
    in >> ch;
    if (ch[0] == '+')
      rec.push_back(pair<int, int>(1, 0));
    else
      in >> x, rec.push_back(pair<int, int>(0, x));
  }
  stack<int> st;
  vector<int> ans;
  reverse(rec.begin(), rec.end());
  for (auto p : rec) {
    if (p.first == 0) {
      if (st.empty() || p.second < st.top())
        st.push(p.second);
      else {
        puts("NO");
        return 0;
      }
    } else {
      if (st.empty()) {
        puts("NO");
        return 0;
      }
      ans.push_back(st.top());
      st.pop();
    }
  }
  if (st.empty()) {
    puts("YES");
    reverse(ans.begin(), ans.end());
    for (int x : ans) printf("%d ", x);
  } else
    puts("NO");
  return 0;
}

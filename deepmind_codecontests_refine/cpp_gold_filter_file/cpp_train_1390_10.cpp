#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
struct nam {
  string s;
  int a, b, c;
};
bool cm(const nam &a, const nam &b) {
  if (a.a != b.a) return a.a > b.a;
  if (a.b != b.b) return a.b > b.b;
  return a.c > b.c;
}
bool cms(const nam &a, const nam &b) { return a.s < b.s; }
vector<nam> m;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    nam na;
    na.a = 0, na.b = 0, na.c = 0;
    cin >> na.s;
    m.push_back(na);
  }
  for (int i = 0; i < n * (n - 1) / 2; i++) {
    char s1[31], s2[31];
    int a, b;
    scanf(" %[^%-]-%s %d:%d", s1, s2, &a, &b);
    for (int j = 0; j < m.size(); j++) {
      m[j].s == s1    ? m[j].a += (a == b) + 3 * (a > b), m[j].b += a - b,
          m[j].c += a : m[j].a;
      m[j].s == s2    ? m[j].a += (a == b) + 3 * (a < b), m[j].b += b - a,
          m[j].c += b : m[j].a;
    }
  }
  sort(m.begin(), m.end(), cm);
  sort(m.begin(), m.begin() + n / 2, cms);
  for (int i = 0; i < n / 2; i++) cout << m[i].s << endl;
  return 0;
}

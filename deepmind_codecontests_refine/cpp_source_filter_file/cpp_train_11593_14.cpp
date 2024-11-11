#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int X, Y, v[4];
string a, b, c;
struct Team {
  string name;
  int a, b, c;
  bool operator<(const Team &p) const {
    if (a == p.a) {
      if (b == p.b) {
        if (c == p.c) return name < p.name;
        return c > p.c;
      }
      return b > p.b;
    }
    return a > p.a;
  }
  void print() { cout << name << " " << a << " " << b << " " << c << endl; }
} tmp[4], s[4];
bool check(int a, int b) {
  for (int i = 0; i < 4; ++i) tmp[i] = s[i];
  tmp[X].a += 3;
  tmp[X].b += a - b, tmp[X].c += a;
  tmp[Y].b += b - a, tmp[Y].c += b;
  sort(tmp, tmp + 4);
  if (tmp[0].name == "BERLAND" || tmp[1].name == "BERLAND") return true;
  return false;
}
void solve() {
  for (int d = 1; d <= 9; ++d)
    for (int a = d; a <= 9; ++a) {
      int b = a - d;
      if (check(a, b)) {
        printf("%d:%d\n", a, b);
        return;
      }
    }
  printf("IMPOSSIBLE\n");
}
int main() {
  for (int i = 0; i < 4; ++i) {
    s[i].name = "";
    s[i].a = s[i].b = s[i].c = 0;
    v[i] = 0;
  }
  for (int i = 0; i < 5; ++i) {
    cin >> a >> b >> c;
    int x = c[0] - '0', y = c[2] - '0';
    for (int j = 0; j < 4; ++j)
      if (s[j].name == a || s[j].name == "") {
        ++v[j];
        s[j].name = a;
        s[j].b += x - y;
        s[j].c += x;
        if (x > y)
          s[j].a += 3;
        else if (x == y)
          s[j].a++;
        break;
      }
    for (int j = 0; j < 4; ++j)
      if (s[j].name == b || s[j].name == "") {
        ++v[j];
        s[j].name = b;
        s[j].b += y - x;
        s[j].c += y;
        if (x < y)
          s[j].a += 3;
        else if (x == y)
          s[j].a++;
        break;
      }
  }
  for (int i = 0; i < 4; ++i)
    if (s[i].name == "BERLAND")
      X = i;
    else if (v[i] != 3)
      Y = i;
  solve();
  return 0;
}

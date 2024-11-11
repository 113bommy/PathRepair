#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
string in(int a) {
  string s;
  if (a == 0) return "+0";
  int b = a;
  a = abs(a);
  while (a > 0) {
    s = (char)(a % 10 + '0') + s;
    a /= 10;
  }
  if (b > 0)
    s = "-" + s;
  else
    s = "+" + s;
  return s;
}
string in1(int a) {
  string s;
  if (a == 0) return "0";
  a = abs(a);
  while (a > 0) {
    s = (char)(a % 10 + '0') + s;
    a /= 10;
  }
  return s;
}
string get(int a, int b) {
  string s = "((abs((t" + in(a + 1) + "))+abs((t" + in(a - 1) + ")))-(abs((t" +
             in(a) + "))+abs((t" + in(a) + "))))";
  s = "(" + in1(b) + "*" + s + ")";
  return s;
}
void solve(int n) {
  int i, j, m, t, a, b;
  vector<int> v[70];
  for (i = 0; i < n; i++) v[i].resize(3);
  for (i = 0; i < n; i++) {
    scanf("%d%d%d", &a, &b, &t);
    v[i][0] = i;
    v[i][1] = (a + a % 2) / 2;
    v[i][2] = (b + b % 2) / 2;
  }
  string s = get(v[0][0], v[0][1]);
  for (i = 1; i < n; i++) {
    s = "(" + s + "+" + get(v[i][0], v[i][1]) + ")";
  }
  printf("%s\n", s.c_str());
  s = get(v[0][0], v[0][2]);
  for (i = 1; i < n; i++) {
    s = "(" + s + "+" + get(v[i][0], v[i][2]) + ")";
  }
  printf("%s\n", s.c_str());
}
int main() {
#pragma comment(linker, "/STACK:1073741824")
  int n, m, k, i;
  scanf("%d", &n);
  solve(n);
  return 0;
}

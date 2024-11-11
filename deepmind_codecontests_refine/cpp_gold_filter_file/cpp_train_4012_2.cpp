#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
void a() {
  int a, b, cnt = 0;
  cin >> a >> b;
  while (a * b > 1) {
    cnt++;
    if (a > b) {
      a -= 2;
      b++;
    } else {
      b -= 2;
      a++;
    }
  }
  cout << cnt;
}
void b() {}
void c() {}
void d() {}
void e() {}
void f() {}
void g() {}
void test() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  a();
  return 0;
}

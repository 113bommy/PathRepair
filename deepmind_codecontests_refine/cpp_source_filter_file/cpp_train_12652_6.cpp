#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
void file() {}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  file();
  int a, ta, b, tb, h, m, bus = 0;
  scanf("%d%d%d%d%d:%d", &a, &ta, &b, &tb, &h, &m);
  int ia = (h * 60) + m, fa = (h * 60) + m + ta;
  for (int i = 300; i < min(fa, 1439); i += b) {
    int f = i + tb;
    if (f > ia) bus++;
  }
  cout << bus;
}

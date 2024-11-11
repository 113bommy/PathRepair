#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
void fast() {
  std::ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
}
int main() {
  fast();
  int a, ta, b, tb, h, m, d, c = 0;
  char ch;
  cin >> a >> ta >> b >> tb >> h >> ch >> m;
  d = h * 60 + m;
  for (int i = 300; (i < d + ta && i < (11 * 60 + 59)); i += b) {
    int f = i + tb;
    if (f > d) c++;
  }
  cout << c;
}
